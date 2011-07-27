#ifndef _FLYENGINE_MATHHELPER_H
#define _FLYENGINE_MATHHELPER_H

#include "Vector.h"
#include <math.h>

#define PI 3.14159265358979323846

struct MathHelper sealed
{
	static void CrossProduct(Vector3 vect1, Vector3 vect2);
	static void Dot(Vector3 vector);
	static void Normalize(Vector3 &vect1, Vector3 &vect2, Vector3 &vect3);

	static float ToRadians(float degrees);
	static double ToRadians(double degrees);

	static float ToDegrees(float radians);
	static double ToDegrees(double radians);

	static float Clamp(float min, float max);
	static double Clamp(double min, double max);
	static int Clamp(int min, int max);
};

#endif 