#ifndef _FLYENGINE_RENDERER_H
#define _FLYENGINE_RENDERER_H

#include "headers.h"
#include "Vector.h"
#include "Matrix.h"
#include "Light.h"

class Renderer
{
protected:	
	int WindowWidth;
	int WindowHeight;

	float NearClippingPlane;
	float FarClippingPlane;

	bool FullScreen;

	FGE_HWND mainWindowHandle;
public:
	Renderer();
	virtual ~Renderer();
	
	virtual bool Initialise(FGE_HWND hWnd, int width, int height, bool fullscreen) = 0;
	virtual void OneTimeInit() = 0;
	virtual void Shutdown() = 0;
	
	virtual void SetClearColour(float R, float G, float B) = 0;
	virtual void Clear(float R, float G, float B, float A) = 0;
	virtual void Clear(int R, int G, int B, int A) = 0;

	virtual void StartRender(bool Colour, bool Depth, bool Stencil) = 0;
	virtual void ClearBuffers(bool Colour, bool Depth, bool Stencil) = 0;
	virtual void EndRendering() = 0;

	virtual void ApplyView(Vector3 cameraPosition, Vector3 viewDirection, Vector3 upDirection) = 0;
	virtual void SetWorldMatrix(Matrix * worldMatrix) = 0;

	virtual void SetLight(Light * light, int index) = 0;
	virtual void DisableLight(int index) = 0;

	virtual void CalculateProjectionMatrix(float fieldOfView, float near, float far) = 0;
	virtual void CalculateOrthogonalMatrix(float near, float far) = 0;
};

#endif