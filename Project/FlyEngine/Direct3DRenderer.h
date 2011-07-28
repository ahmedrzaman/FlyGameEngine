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
	D3DXCOLOR clearColour;
public:
	Direct3DRenderer();
	~Direct3DRenderer();

	bool Initialise(int width, int height, HWND mainWindow, bool fullscreen);
	void OneTimeInit();
	void Shutdown();
};

#endif