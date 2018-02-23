#include "Matrix4.h"
#include <iostream>
#include "Math.h"


Matrix4::Matrix4()
{
	mat[0][0] = 1; mat[0][1] = 0; mat[0][2] = 0; mat[0][3] = 0;
	mat[1][0] = 0; mat[1][1] = 1; mat[1][2] = 0; mat[1][3] = 0;
	mat[2][0] = 0; mat[2][1] = 0; mat[2][2] = 1; mat[2][3] = 0;
	mat[3][0] = 0; mat[3][1] = 0; mat[3][2] = 0; mat[3][3] = 1;
}

Matrix4::Matrix4(float a00, float a01, float a02, float a03, float a10, float a11, float a12, float a13, 
				 float a20, float a21, float a22, float a23, float a30, float a31, float a32, float a33)
{

	mat[0][0] = a00; mat[0][1] = a01; mat[0][2] = a02; mat[0][3] = a03;
	mat[1][0] = a10; mat[1][1] = a11; mat[1][2] = a12; mat[1][3] = a13;
	mat[2][0] = a20; mat[2][1] = a21; mat[2][2] = a22; mat[2][3] = a23;
	mat[3][0] = a30; mat[3][1] = a31; mat[3][2] = a32; mat[3][3] = a33;
}

//adition
const Matrix4 Matrix4::operator+ (const Matrix4 & rhs) const
{
	return Matrix4(mat[0][0] + rhs.mat[0][0], mat[0][1] + rhs.mat[0][1], mat[0][2] + rhs.mat[0][2], mat[0][3] + rhs.mat[0][3],
				   mat[1][0] + rhs.mat[1][0], mat[1][1] + rhs.mat[1][1], mat[1][2] + rhs.mat[1][2], mat[1][3] + rhs.mat[1][3],
				   mat[2][0] + rhs.mat[2][0], mat[2][1] + rhs.mat[2][1], mat[2][2] + rhs.mat[2][2], mat[2][3] + rhs.mat[2][3],
				   mat[3][0] + rhs.mat[3][0], mat[3][1] + rhs.mat[3][1], mat[3][2] + rhs.mat[3][2], mat[3][3] + rhs.mat[3][3]);
}

//subraction
const Matrix4 Matrix4::operator- (const Matrix4 & rhs) const
{
	return Matrix4(mat[0][0] - rhs.mat[0][0], mat[0][1] - rhs.mat[0][1], mat[0][2] - rhs.mat[0][2], mat[0][3] - rhs.mat[0][3],
				   mat[1][0] - rhs.mat[1][0], mat[1][1] - rhs.mat[1][1], mat[1][2] - rhs.mat[1][2], mat[1][3] - rhs.mat[1][3],
				   mat[2][0] - rhs.mat[2][0], mat[2][1] - rhs.mat[2][1], mat[2][2] - rhs.mat[2][2], mat[2][3] - rhs.mat[2][3],
				   mat[3][0] - rhs.mat[3][0], mat[3][1] - rhs.mat[3][1], mat[3][2] - rhs.mat[3][2], mat[3][3] - rhs.mat[3][3]);
}
//multiplication
const Matrix4 Matrix4::operator* (const Matrix4 & rhs) const
{
	Matrix4 result;
	
	result.mat[0][0] = rhs.mat[0][0] * mat[0][0] + rhs.mat[0][1] * mat[1][0] + rhs.mat[0][2] * mat[2][0] + rhs.mat[0][3] * mat[3][0];
	result.mat[0][1] = rhs.mat[0][0] * mat[0][1] + rhs.mat[0][1] * mat[1][1] + rhs.mat[0][2] * mat[2][1] + rhs.mat[0][3] * mat[3][1];
	result.mat[0][2] = rhs.mat[0][0] * mat[0][2] + rhs.mat[0][1] * mat[1][2] + rhs.mat[0][2] * mat[2][2] + rhs.mat[0][3] * mat[3][2];
	result.mat[0][3] = rhs.mat[0][0] * mat[0][3] + rhs.mat[0][1] * mat[1][3] + rhs.mat[0][2] * mat[2][3] + rhs.mat[0][3] * mat[3][3];

	result.mat[1][0] = rhs.mat[1][0] * mat[0][0] + rhs.mat[1][1] * mat[1][0] + rhs.mat[1][2] * mat[2][0] + rhs.mat[1][3] * mat[3][0];
	result.mat[1][1] = rhs.mat[1][0] * mat[0][1] + rhs.mat[1][1] * mat[1][1] + rhs.mat[1][2] * mat[2][1] + rhs.mat[1][3] * mat[3][1];
	result.mat[1][2] = rhs.mat[1][0] * mat[0][2] + rhs.mat[1][1] * mat[1][2] + rhs.mat[1][2] * mat[2][2] + rhs.mat[1][3] * mat[3][2];
	result.mat[1][3] = rhs.mat[1][0] * mat[0][3] + rhs.mat[1][1] * mat[1][3] + rhs.mat[1][3] * mat[2][3] + rhs.mat[1][3] * mat[3][3];

	result.mat[2][0] = rhs.mat[2][0] * mat[0][0] + rhs.mat[2][1] * mat[1][0] + rhs.mat[2][2] * mat[2][0] + rhs.mat[2][3] * mat[3][0];
	result.mat[2][1] = rhs.mat[2][0] * mat[0][1] + rhs.mat[2][1] * mat[1][1] + rhs.mat[2][2] * mat[2][1] + rhs.mat[2][3] * mat[3][1];
	result.mat[2][2] = rhs.mat[2][0] * mat[0][2] + rhs.mat[2][1] * mat[1][2] + rhs.mat[2][2] * mat[2][2] + rhs.mat[2][3] * mat[3][2];
	result.mat[2][3] = rhs.mat[2][0] * mat[0][3] + rhs.mat[2][1] * mat[1][3] + rhs.mat[2][2] * mat[2][3] + rhs.mat[2][3] * mat[3][3];

	result.mat[3][0] = rhs.mat[3][0] * mat[0][0] + rhs.mat[3][1] * mat[1][0] + rhs.mat[3][2] * mat[2][0] + rhs.mat[3][3] * mat[3][0];
	result.mat[3][1] = rhs.mat[3][0] * mat[0][1] + rhs.mat[3][1] * mat[1][1] + rhs.mat[3][2] * mat[2][1] + rhs.mat[3][3] * mat[3][1];
	result.mat[3][2] = rhs.mat[3][0] * mat[0][2] + rhs.mat[3][1] * mat[1][2] + rhs.mat[3][2] * mat[2][2] + rhs.mat[3][3] * mat[3][2];
	result.mat[3][3] = rhs.mat[3][0] * mat[0][3] + rhs.mat[3][1] * mat[1][3] + rhs.mat[3][2] * mat[2][3] + rhs.mat[3][3] * mat[3][3];
	
	return result;
}

const Matrix4 Matrix4::transpose()
{
	 
	Matrix4 trans;

	trans.mat[0][0] = mat[0][0];
	trans.mat[0][1] = mat[1][0];
	trans.mat[0][2] = mat[2][0];
	trans.mat[0][3] = mat[3][0];

	trans.mat[1][0] = mat[0][1];
	trans.mat[1][1] = mat[1][1];
	trans.mat[1][2] = mat[2][1];
	trans.mat[1][3] = mat[3][1];

	trans.mat[2][0] = mat[0][2];
	trans.mat[2][1] = mat[1][2];
	trans.mat[2][2] = mat[2][2];
	trans.mat[2][3] = mat[3][2];

	trans.mat[3][0] = mat[0][3];
	trans.mat[3][1] = mat[1][3];
	trans.mat[3][2] = mat[2][3];
	trans.mat[3][3] = mat[3][3];

	return trans;
}

const Vector4 Matrix4::operator* (const Vector4 & rhs) const
{
	Vector4 result;

	result.x = mat[0][0] * rhs.x + mat[1][0] * rhs.y + mat[2][0] * rhs.z + mat[3][0] * rhs.w;
	result.y = mat[0][1] * rhs.x + mat[1][1] * rhs.y + mat[2][1] * rhs.z + mat[3][1] * rhs.w;
	result.z = mat[0][2] * rhs.x + mat[1][2] * rhs.y + mat[2][2] * rhs.z + mat[3][2] * rhs.w;
	result.w = rhs.w;

	return result;
}

Matrix4::~Matrix4()
{

}