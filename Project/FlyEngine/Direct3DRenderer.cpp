#include "Direct3DRenderer.h"
#include "headers.h"

bool NullErrorCheck(void * object, char * title, char * message)
{
	if (!object)
	{ ShowMessage(title, message); return false; }

	return true;
}

void ShowMessage(char * title, char * message)
{
	MessageBox(NULL, message, title, 0);
}

Direct3DRenderer::Direct3DRenderer()
{
	Direct3D = NULL;
	GraphicsDevice = NULL;
}

Direct3DRenderer::~Direct3DRenderer()
{
	Shutdown();
}

bool Direct3DRenderer::Initialise(FGE_HWND hWnd, int width, int height, bool fullscreen)
{
	Shutdown();
	
	mainWindowHandle = hWnd;
	if (!mainWindowHandle) 
	{
		ShowMessage("Handle", "ERROR: Main window handle is not created, this will cause trouble whilst setting up Direct3D in the window");
		return FGE_ERROR;
	}

	FullScreen = fullscreen;

	D3DDISPLAYMODE displayMode;
	D3DCAPS9 deviceCapabilities;
	D3DPRESENT_PARAMETERS presentationParams;

	ZeroMemory(&presentationParams, sizeof (presentationParams));

	// set up Direct3D
	Direct3D = Direct3DCreate9(D3D9b_SDK_VERSION);

	if (NullErrorCheck(Direct3D, "Direct3D", "Error in initialising Direct3D"))
		return FGE_ERROR;

	//if (!Direct3D) 
	//{ ShowMessage("Direct3D", "ERROR: Direct3D is not created!"); return FGE_ERROR; }

	if (FAILED(Direct3D->GetAdapterDisplayMode(D3DADAPTER_DEFAULT, &displayMode)))
	{ ShowMessage("Display Mode", "ERROR: Adapter display mode is not retrieved!"); return FGE_ERROR; }
	
	// set up device capabilities
	DWORD processing = 0;
	if (deviceCapabilities.VertexProcessingCaps != 0)
		processing = D3DCREATE_HARDWARE_VERTEXPROCESSING | D3DCREATE_PUREDEVICE;
	else
		processing = D3DCREATE_SOFTWARE_VERTEXPROCESSING;
	
	// initialise device presentation parameters
	if (FullScreen)
	{
		presentationParams.FullScreen_RefreshRateInHz = displayMode.RefreshRate;
		presentationParams.PresentationInterval = D3DPRESENT_INTERVAL_DEFAULT;
	}
	else
		presentationParams.PresentationInterval = D3DPRESENT_INTERVAL_IMMEDIATE;

	presentationParams.Windowed = !FullScreen;
	presentationParams.BackBufferWidth = width;
	presentationParams.BackBufferHeight = height;
	presentationParams.hDeviceWindow = mainWindowHandle;
	presentationParams.SwapEffect = D3DSWAPEFFECT_DISCARD;
	presentationParams.BackBufferFormat = displayMode.Format;
	presentationParams.BackBufferCount = 1;
	presentationParams.EnableAutoDepthStencil = TRUE;
	presentationParams.AutoDepthStencilFormat = D3DFMT_D16;

	WindowWidth = width;
	WindowHeight = height;
	
	// set up graphics device
	Direct3D->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, mainWindowHandle, processing, &presentationParams, &GraphicsDevice);
	if (GraphicsDevice == NULL)
	{ ShowMessage("Graphics Device", "ERROR: Graphics device is not setting up!"); return FGE_ERROR; }

	OneTimeInit();

	return FGE_OK;
}

void Direct3DRenderer::OneTimeInit()
{
	if (NullErrorCheck(GraphicsDevice, "Graphics Device", "Graphics device has not been initialised!"))
		return;
	//if (!GraphicsDevice) 
	//{ ShowMessage("OneTimeInit:", "ERROR: Graphics device is not set up properly."); return; }

	GraphicsDevice->SetRenderState(D3DRS_LIGHTING, FALSE);
	GraphicsDevice->SetRenderState(D3DRS_CULLMODE, D3DCULL_NONE);
	GraphicsDevice->SetRenderState(D3DRS_ZENABLE, TRUE);

	CalculateProjectionMatrix(D3DX_PI / 4, 0.1f, 1000);
}

void Direct3DRenderer::Shutdown()
{
	// release all the graphical assets etc...
	// models
	// guis
	// textures
	
	// release the graphcis device and direct3d
	if (GraphicsDevice) GraphicsDevice->Release();
	if (Direct3D) Direct3D->Release();

	GraphicsDevice = NULL;
	Direct3D = NULL;
}

void Direct3DRenderer::SetClearColour(float R, float G, float B)
{
	ClearColour = D3DCOLOR_COLORVALUE(R, G, B, 1.0f);
}

void Direct3DRenderer::Begin(bool colour, bool depth, bool stencil)
{
	if (NullErrorCheck(GraphicsDevice, "Graphics Device", "Graphics device has not been initialised!"))
		return;

	unsigned int buffers = 0;
	if (colour) buffers |= D3DCLEAR_TARGET;
	if (depth) buffers |= D3DCLEAR_ZBUFFER;
	if (stencil) buffers |= D3DCLEAR_STENCIL;

	if (FAILED(GraphicsDevice->Clear(0, NULL, buffers, ClearColour, 1, 0)))
	{
		ShowMessage("Error", "Graphics device is not clearing");
		return;
	}

	if (FAILED(GraphicsDevice->BeginScene()))
	{
		ShowMessage("Error", "Graphics device failed to begin scene");
		return;
	}

	RenderingScene = true;
	functionBeginCalled = true;
}

void Direct3DRenderer::End()
{
	if (!functionBeginCalled)
	{
		ShowMessage("Error", "Cannot call End without calling Begin");
		return;
	}

	GraphicsDevice->EndScene();
	GraphicsDevice->Present(NULL, NULL, NULL, NULL);

	RenderingScene = false;
	functionBeginCalled = false;
}

void Direct3DRenderer::ClearBuffers(bool colour, bool depth, bool stencil)
{
	if (!functionBeginCalled)
	{
		ShowMessage("Error", "Cannot call ClearBuffers without calling Begin");
		return;
	}
	
	unsigned int buffers = 0;
	if (colour) buffers |= D3DCLEAR_TARGET;
	if (depth) buffers |= D3DCLEAR_ZBUFFER;
	if (stencil) buffers |= D3DCLEAR_STENCIL;

	if (RenderingScene)	GraphicsDevice->EndScene();
	if ( FAILED(GraphicsDevice->Clear(0, NULL, buffers, ClearColour, 1, 0)))
		return;

	if (RenderingScene)
		if (FAILED(GraphicsDevice->BeginScene())) return;
}

void Direct3DRenderer::SetLight(Light * light, int index)
{
	if (!GraphicsDevice)
	{ ShowMessage("Function: SetLight", "Initialise light before trying to set it"); return; }
	if (!light)
	{ ShowMessage("Function: SetLight", "Initialise light before trying to set it"); return; }

	D3DLIGHT9 d3dlight;

	d3dlight.Ambient.r = light->Ambient.R;
	d3dlight.Ambient.g = light->Ambient.G;
	d3dlight.Ambient.b = light->Ambient.B;
	d3dlight.Ambient.a = light->Ambient.A;
	d3dlight.Attenuation0 = light->Attenuation0;
	d3dlight.Attenuation1 = light->Attenuation1;
	d3dlight.Attenuation2 = light->Attenuation2;
	d3dlight.Diffuse.r = light->Diffuse.R;
	d3dlight.Diffuse.g = light->Diffuse.G;
	d3dlight.Diffuse.b = light->Diffuse.B;
	d3dlight.Diffuse.a = light->Diffuse.A;
	d3dlight.Falloff = light->FallOff;
	d3dlight.Phi = light->Phi;
	d3dlight.Direction.x = light->Direction.X;
	d3dlight.Direction.y = light->Direction.Y;
	d3dlight.Direction.z = light->Direction.Z;
}

void Direct3DRenderer::DisableLight(int index)
{
}

void Direct3DRenderer::CalculateProjectionMatrix(float fieldOfView, float near, float far)
{
	if (!GraphicsDevice)
	{ ShowMessage("Graphics Device Error", "ERROR: Initialise the renderer before calculating the project matrix!"); return; }

	D3DXMatrixPerspectiveFovLH(&projectionMatrix, fieldOfView, float(WindowWidth /WindowHeight), FLOAT(near), FLOAT(far));
	GraphicsDevice->SetTransform(D3DTS_PROJECTION, &projectionMatrix);
}

void Direct3DRenderer::CalculateOrthogonalMatrix(float near, float far)
{
	if (!GraphicsDevice)
	{ ShowMessage("Graphics Device Error", "ERROR: Initialise the renderer before calculating the project matrix!"); return; }

	D3DXMatrixOrthoLH(&projectionMatrix, WindowWidth, WindowHeight, FLOAT(near), FLOAT(far));
	GraphicsDevice->SetTransform(D3DTS_PROJECTION, &projectionMatrix);
}
