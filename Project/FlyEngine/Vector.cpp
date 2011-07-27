#include "Vector.h"

const Vector3 Vector3::One = Vector3(1, 1, 1);

Vector3 Vector3::operator -(Vector3 &vector)
{
	return Vector3(X - vector.X, Y - vector.Y, Z - vector.Z);
}
Vector3	Vector3::operator +(Vector3 &vector)
{
	return Vector3(X + vector.X, Y + vector.Y, Z + vector.Z);
}
Vector3 Vector3::operator /(Vector3 &vector)
{
	return Vector3(X / vector.X, Y / vector.Y, Z / vector.Z);
}
Vector3 Vector3::operator *(Vector3 &vector)
{
	return Vector3(X * vector.X, Y * vector.Y, Z * vector.Z);
}
Vector3 Vector3::operator -(float scaleFactor)
{
	return Vector3(X - scaleFactor, Y - scaleFactor, Z - scaleFactor);
}
Vector3 Vector3::operator +(float scaleFactor)
{
	return Vector3(X + scaleFactor, Y + scaleFactor, Z + scaleFactor);
}
Vector3 Vector3::operator /(float scaleFactor)
{
	return Vector3(X / scaleFactor, Y / scaleFactor, Z / scaleFactor);
}
Vector3 Vector3::operator *(float scaleFactor)
{
	return Vector3(X * scaleFactor, Y * scaleFactor, Z * scaleFactor);
}
	
void Vector3::operator -=(Vector3 &vector)
{
	X -= vector.X;
	Y -= vector.Y;
	Z -= vector.Z;
}
void Vector3::operator +=(Vector3 &vector)
{
	X += vector.X;
	Y += vector.Y;
	Z += vector.Z;
}
void Vector3::operator /=(Vector3 &vector)
{
	X /= vector.X;
	Y /= vector.Y;
	Z /= vector.Z;
}
void Vector3::operator *=(Vector3 &vector)
{
	X *= vector.X;
	Y *= vector.Y;
	Z *= vector.Z;
}
void Vector3::operator -=(float scaleFactor)
{
	X -= scaleFactor;
	Y -= scaleFactor;
	Z -= scaleFactor;
}
void Vector3::operator +=(float scaleFactor)
{
	X += scaleFactor;
	Y += scaleFactor;
	Z += scaleFactor;
}
void Vector3::operator /=(float scaleFactor)
{
	X /= scaleFactor;
	Y /= scaleFactor;
	Z /= scaleFactor;
}
void Vector3::operator *=(float scaleFactor)
{
	X *= scaleFactor;
	Y *= scaleFactor;
	Z *= scaleFactor;
}

Vector3 Vector3::operator =(Vector3 &vector)
{
	return Vector3(vector.X, vector.Y, vector.Z);
}

bool Vector3::operator ==(const Vector3 &vector) const
{
	if (X != vector.X)
		return false;
	if (Y != vector.Y)
		return false;
	if (Z != vector.Z)
		return false;
		
	return true;
}

float Vector3::Length()
{
	return (float(sqrt((X * X) + (Y * Y) + (Z * Z))));
}

void Vector3::Normalize()
{
	float length = Length();

	if (length == 0.0f) length = 1.0f;

	X = X / length;
	Y = Y / length;
	Z = Z / length;
}



const Vector2 Vector2::One = Vector2(1, 1);

Vector2 Vector2::operator -(Vector2 &vector)
{
	return Vector2(X - vector.X, Y - vector.Y);
}
Vector2	Vector2::operator +(Vector2 &vector)
{
	return Vector2(X + vector.X, Y + vector.Y);
}
Vector2 Vector2::operator /(Vector2 &vector)
{
	return Vector2(X / vector.X, Y / vector.Y);
}
Vector2 Vector2::operator *(Vector2 &vector)
{
	return Vector2(X * vector.X, Y * vector.Y);
}
Vector2 Vector2::operator -(float scaleFactor)
{
	return Vector2(X - scaleFactor, Y - scaleFactor);
}
Vector2 Vector2::operator +(float scaleFactor)
{
	return Vector2(X + scaleFactor, Y + scaleFactor);
}
Vector2 Vector2::operator /(float scaleFactor)
{
	return Vector2(X / scaleFactor, Y / scaleFactor);
}
Vector2 Vector2::operator *(float scaleFactor)
{
	return Vector2(X * scaleFactor, Y * scaleFactor);
}
	
void Vector2::operator -=(Vector2 &vector)
{
	X -= vector.X;
	Y -= vector.Y;
}
void Vector2::operator +=(Vector2 &vector)
{
	X += vector.X;
	Y += vector.Y;
}
void Vector2::operator /=(Vector2 &vector)
{
	X /= vector.X;
	Y /= vector.Y;
}
void Vector2::operator *=(Vector2 &vector)
{
	X *= vector.X;
	Y *= vector.Y;
}
void Vector2::operator -=(float scaleFactor)
{
	X -= scaleFactor;
	Y -= scaleFactor;
}
void Vector2::operator +=(float scaleFactor)
{
	X += scaleFactor;
	Y += scaleFactor;
}
void Vector2::operator /=(float scaleFactor)
{
	X /= scaleFactor;
	Y /= scaleFactor;
}
void Vector2::operator *=(float scaleFactor)
{
	X *= scaleFactor;
	Y *= scaleFactor;
}

Vector2 Vector2::operator =(Vector2 &vector)
{
	return Vector2(vector.X, vector.Y);
}

bool Vector2::operator ==(const Vector2 &vector) const
{
	if (X != vector.X)
		return false;
	if (Y != vector.Y)
		return false;
		
	return true;
}

float Vector2::Length()
{
	return (float(sqrt((X * X) + (Y * Y))));
}

void Vector2::Normalize()
{
	float length = Length();

	if (length == 0.0f) length = 1.0f;

	X = X / length;
	Y = Y / length;
}