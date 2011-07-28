#ifndef _FLYENGINE_RENDERER_H
#define _FLYENGINE_RENDERER_H

#include "headers.h"
#include "Vector.h"

class Renderer
{
protected:	
	int BackBufferWidth;
	int BackBufferHeight;

	float NearClippingPlane;
	float FarClippingPlane;

	bool IsFullscreen;
public:
	Renderer();
	virtual ~Renderer();
	
	virtual void SetClearColour(float R, float G, float B) = 0;
	virtual void Clear(float R, float G, float B, float A) = 0;
	virtual void Clear(int R, int G, int B, int A) = 0;

	virtual void StartRender(bool Colour, bool Depth, bool Stencil) = 0;
	virtual void ClearBuffers(bool Colour, bool Depth, bool Stencil) = 0;
	virtual void EndRendering() = 0;
};

#endif