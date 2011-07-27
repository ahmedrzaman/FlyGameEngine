#ifndef _FLYENGINE_MATRIX_H
#define _FLYENGINE_MATRIX_H

#include "Vector.h"

class Matrix
{
public:
	float matrix[16];
	
	void Identity();

	Matrix() ;
	Matrix(Matrix &mat);
	~Matrix() { };


	void Translate(Vector3 &translate);
	void Translate(float x, float y, float z);
	void InverseTranslate();

	void Rotate(double angle, int x, int y , int z);
	void RotateX(double angle);
	void RotateY(double angle);
	void RotateZ(double angle);

	Vector3 VectorMatrixMultiply(Vector3 &vector);
	Vector3 VectorMatrixMultiply3x3(Vector3 &vector);

};

#endif