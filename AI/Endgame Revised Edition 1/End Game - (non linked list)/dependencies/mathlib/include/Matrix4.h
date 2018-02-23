#pragma once

#include <cmath>
#include "Vector4.h"

class Matrix4
{
public:

	//create a Matrix class representing a 3x3 grid of floats.
	//Matrix4(float, float, float, float,
	//		float, float, float, float,
	//		float, float, float, float,
	//		float, float, float, float);

	//constructor with no parameters (sets matrix to identity)

	Matrix4();

	//constructor with 9 arguments, sets each value in matrix to passed in value.
	Matrix4(float a00, float a01, float a02, float a03,
			float a10, float a11, float a12, float a13,
			float a20, float a21, float a22, float a23,
			float a30, float a31, float a32, float a33);


	//matrix addition (operator overload similar to vector addition)
	const Matrix4 operator+ (const Matrix4 & rhs) const;
	
	//matrix subtraction
	const Matrix4 operator- (const Matrix4 & rhs) const;

	//matrix multiplication Matrix4*Matrix4.
	const Matrix4 operator* (const Matrix4 & rhs) const;
	
	//transpose
	const Matrix4 transpose();
	//Do the same for Matrix4.
	~Matrix4();

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
	void setRotateZ (float a_rotation)
	{
		mat[0][0] = cos(a_rotation);
		mat[0][1] = sin(a_rotation);
		mat[1][0] = -sin(a_rotation);
		mat[1][1] = cos(a_rotation);
	}

	void setScale(float x, float y, float z)
	{
		mat[0][0] = x;
		mat[1][1] = y;
		mat[2][2] = z;

	}

	void setTranslate(float x, float y, float z)
	{
		mat[0][3] = x;
		mat[1][3] = y;
		mat[2][3] = z;

	}

	explicit operator float*()
	{
		return &mat[0][0];
	}

	const Vector4 operator* (const Vector4 & rhs) const;
	Vector4& operator[](int index)
	{
		return *(Vector4*)(mat[index]);
	}
private:
	float mat[4][4];
};
