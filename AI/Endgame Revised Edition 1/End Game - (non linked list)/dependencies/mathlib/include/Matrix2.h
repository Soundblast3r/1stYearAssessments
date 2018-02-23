#pragma once

#include <cmath>
#include "Vector2.h"

class Matrix2
{ 
public:

	//create a Matrix class representing a 2x2 grid of floats.
	//Matrix2(float, float, 
	//		float, float);
	
	//constructor with no parameters (sets matrix to identity)

	Matrix2();
	
	//constructor with 4 arguments, sets each value in matrix to passed in value.
	Matrix2(float a00, float a01, 
			float a10, float a11);

	
	//matrix addition (operator overload similar to vector addition)
	const Matrix2 operator+ (const Matrix2 & rhs) const;
	
	//matrix subtraction
	const Matrix2 operator- (const Matrix2 & rhs) const;

	//matrix multiplication Matrix2*Matrix2.
	const Matrix2 operator* (const Matrix2 & rhs) const;

	//matrix multiplication Matrix2*Matrix2.
	const Vector2 operator* (const Vector2 & rhs) const;

	const Matrix2 transpose();

	//Do the same for Matrix3 and Matrix4.
	~Matrix2();

	explicit operator float*()
	{
		return &mat[0][0];
	}

	//set the scale - 
	void setScale(float a_scale)
	{
		//set element 00 of the matrix to a_scale
		mat[0][0] = a_scale;
		

		//set element 11 of the matrix to a_scale
		mat[1][1] = a_scale;
	}

	void setRotate(float a_rotation)
	{
		mat[0][0] = cos(a_rotation);
		mat[0][1] = sin(a_rotation);
		mat[1][0] = -sin(a_rotation);
		mat[1][1] = cos(a_rotation);
	}

	Vector2& operator[](int index)
	{
		return *(Vector2*)(mat[index]);
	}

	private:
		float mat[2][2];
};