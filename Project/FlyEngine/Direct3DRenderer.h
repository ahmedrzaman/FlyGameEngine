#ifndef _FLYENGINE_DIRECT3DRENDERER_H
#define _FLYENGINE_DIRECT3DRENDERER_H

#include "Renderer.h"
#include <d3d9.h>
#include <d3dx9.h>

#pragma comment (lib, "d3d9.lib")
#pragma comment (lib, "d3dx9.lib")

class Direct3DRenderer : public Renderer
{
private:
	LPDIRECT3D9 Direct3D;
	LPDIRECT3DDEVICE9 GraphicsDevice;
	D3DCOLOR ClearColour;

	D3DXMATRIX projectionMatrix;
	
	void ShowMessage(char * title, char * message);

public:
	Direct3DRenderer();
	~Direct3DRenderer();

	bool Initialise(FGE_HWND hWnd, int width, int height, bool fullscreen);
	void OneTimeInit();
	void Shutdown();
	
	void SetClearColour(float R, float G, float B);
	void Clear(float R, float G, float B, float A);
	void Clear(int R, int G, int B, int A);

	void StartRender(bool Colour, bool Depth, bool Stencil);
	void ClearBuffers(bool Colour, bool Depth, bool Stencil);
	void EndRendering() = 0;

	void ApplyView(Vector3 cameraPosition, Vector3 viewDirection, Vector3 upDirection);
	void SetWorldMatrix(Matrix * worldMatrix);
	
	void SetLight(Light * light, int index);
	void DisableLight(int index);
	
	void CalculateProjectionMatrix(float fieldOfView, float near, float far);
	void CalculateOrthogonalMatrix(float near, float far);
};



#endif