#pragma once

#include <cmath>
#include "Vector3.h"

class Matrix3
{
public:

	//create a Matrix class representing a 3x3 grid of floats.
	//Matrix3(float, float, float, 
	//		float, float, float,
	//		float, float, float);

	//constructor with no parameters (sets matrix to identity)

	Matrix3();

	//constructor with 9 arguments, sets each value in matrix to passed in value.
	Matrix3(float a00, float a01, float a02, 
			float a10, float a11, float a12,
			float a20, float a21, float a22);


	//matrix addition (operator overload similar to vector addition)
	Matrix3 operator+ (const Matrix3 & rhs) const;
	//matrix subtraction
	Matrix3 operator- (const Matrix3 & rhs) const;

	//matrix multiplication Matrix3*Matrix3.
	Matrix3 operator* (const Matrix3 & rhs) const;

	const Matrix3 transpose();

	//Do the same for Matrix4.
	~Matrix3();

	explicit operator float*()
	{
		return &mat[0][0];
	}

	//add setRotate and setScale
	void setScale(float a_scale)
	{
		//set element 00 of the matrix to a_scale
		mat[0][0] = a_scale;

		//set element 11 of the matrix to a_scale
		mat[1][1] = a_scale;

		//set element 22 of the matrix to a_scale
		mat[2][2] = a_scale;
	}

	void setRotateX(float a_rotation)
	{
		mat[1][1] = cos(a_rotation);
		mat[1][2] = sin(a_rotation);
		mat[2][1] = -sin(a_rotation);
		mat[2][2] = cos(a_rotation);
	}

	void setRotateY(float a_rotation)
	{
		mat[0][0] = cos(a_rotation);
		mat[0][2] = -sin(a_rotation);
		mat[2][0] = sin(a_rotation);
		mat[2][2] = cos(a_rotation);
	}
	void setRotateZ(float a_rotation)
	{
		mat[0][0] = cos(a_rotation);
		mat[0][1] = sin(a_rotation);
		mat[1][0] = -sin(a_rotation);
		mat[1][1] = cos(a_rotation);
	}

	//add setTranslate(float x, float y)
	void setTranslate(float x, float y)
	{
		mat[2][0] = x;
		mat[2][1] = y;
	}


	const Vector3 operator* (const Vector3 & rhs) const;

	Vector3& operator[](int index)
	{
		return *(Vector3*)(mat[index]);
	}

private:
	float mat[3][3];
};
