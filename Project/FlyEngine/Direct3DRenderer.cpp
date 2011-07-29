#include "Direct3DRenderer.h"
#include "headers.h"

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
	if (!Direct3D) 
	{ ShowMessage("Direct3D", "ERROR: Direct3D is not created!"); return FGE_ERROR; }

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
	if (!GraphicsDevice) 
	{ ShowMessage("OneTimeInit:", "ERROR: Graphics device is not set up properly."); return; }

	GraphicsDevice->SetRenderState(D3DRS_LIGHTING, FALSE);
	GraphicsDevice->SetRenderState(D3DRS_CULLMODE, D3DCULL_NONE);
	GraphicsDevice->SetRenderState(D3DRS_ZENABLE, TRUE);
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

void Direct3DRenderer::CalculateProjectionMatrix(float fieldOfView, float near, float far)
{
	if (!GraphicsDevice)
	{ ShowMessage("Graphics Device Error", "ERROR: Initialise the renderer before calculating the project matrix!"); return; }

	D3DXMatrixPerspectiveFovLH(
}
void Direct3DRenderer::CalculateOrthogonalMatrix(float near, float far)
{
}

void Direct3DRenderer::ShowMessage(char * title, char * message)
{
	MessageBox(NULL, message, title, 0);
}