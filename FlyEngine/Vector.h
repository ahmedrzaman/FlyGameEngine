#ifndef _FLYENGINE_VECTOR_H
#define _FLYENGINE_VECTOR_H

#include <math.h>

class Vector3 
{
public:	
	static const Vector3 One;

	float X, Y, Z;

	Vector3() : X(0), Y(0), Z(0) { }
	Vector3(float x, float y, float z) : X(x), Y(y), Z(z) { }
	~Vector3() { }

	// operators
	Vector3 operator -(Vector3 &vector);
	Vector3 operator +(Vector3 &vector);
	Vector3 operator /(Vector3 &vector);
	Vector3 operator *(Vector3 &vector);
	Vector3 operator -(float amount);
	Vector3 operator +(float amount);
	Vector3 operator /(float amount);
	Vector3 operator *(float amount);

	Vector3 operator =(Vector3 &vector);
	
	void operator -=(Vector3 &vector);
	void operator +=(Vector3 &vector);
	void operator /=(Vector3 &vector);
	void operator *=(Vector3 &vector);
	void operator -=(float vector);
	void operator +=(float vector);
	void operator /=(float vector);
	void operator *=(float vector);

	bool operator ==(const Vector3 &vector) const;

	float Length();
	void Normalize();
};

class Vector2 
{
public:
	static const Vector2 One;
	float X, Y;

	Vector2() : X(0), Y(0) { }
	Vector2(float x, float y) : X (x), Y(y) { }
	~Vector2() { }

	// operators
	Vector2 operator -(Vector2 &vector);
	Vector2 operator +(Vector2 &vector);
	Vector2 operator /(Vector2 &vector);
	Vector2 operator *(Vector2 &vector);
	Vector2 operator -(float amount);
	Vector2 operator +(float amount);
	Vector2 operator /(float amount);
	Vector2 operator *(float amount);

	Vector2 operator =(Vector2 &vector);
	
	void operator -=(Vector2 &vector);
	void operator +=(Vector2 &vector);
	void operator /=(Vector2 &vector);
	void operator *=(Vector2 &vector);
	void operator -=(float vector);
	void operator +=(float vector);
	void operator /=(float vector);
	void operator *=(float vector);

	bool operator ==(const Vector2 &vector) const;

	float Length();
	void Normalize();
};

#endif 