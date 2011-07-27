#ifndef _FLYENGINE_RENDERER_H
#define _FLYENGINE_RENDERER_H

#include "headers.h"
#include "Vector.h"

class Renderer
{
public:
	Renderer();
	~Renderer();
	
	int BackBufferWidth;
	int BackBufferHeight;

	float NearClippingPlane;
	float FarClippingPlane;

	bool IsFullscreen;
	
	void SetClearColour(float R, float G, float B);
	void Clear(float R, float G, float B, float A);
	void Clear(int R, int G, int B, int A);

	void StartRender(bool Colour, bool Depth, bool Stencil);
	void ClearBuffers(bool Colour, bool Depth, bool Stencil);
	void EndRendering();
};

#endif