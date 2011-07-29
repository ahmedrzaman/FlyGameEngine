#ifndef _FLYENGINE_LIGHT_H
#define _FLYENGINE_LIGHT_H

#include "Vector.h"
#include "Colour.h"

enum LightType
{
	LIGHT_POINT = 1,
	LIGHT_DIRECTIONAL = 2,
	LIGHT_SPOT = 3,
};

struct Light
{
	Light();
	
	LightType Type;
	Vector3 Position;
	Vector3 Direction;
	Colour Ambient;
	Colour Diffuse;
	Colour Specular;

	float Range;
	float FallOff;
	float Attenuation0, Attenuation1, Attenuation2;
	float Theta;
	float Phi;
};

#endif