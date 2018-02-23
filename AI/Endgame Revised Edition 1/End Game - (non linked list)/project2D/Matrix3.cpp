#include "Matrix3.h"
#include <iostream>
#include "Math.h"


Matrix3::Matrix3()
{
	mat[0][0] = 1; mat[0][1] = 0; mat[0][2] = 0;
	mat[1][0] = 0; mat[1][1] = 1; mat[1][2] = 0;
	mat[2][0] = 0; mat[2][1] = 0; mat[2][2] = 1;
}

Matrix3::Matrix3(float a00, float a01, float a02, float a10, float a11, float a12, float a20, float a21, float a22)
{
	mat[0][0] = a00; mat[0][1] = a01; mat[0][2] = a02;
	mat[1][0] = a10; mat[1][1] = a11; mat[1][2] = a12;
	mat[2][0] = a20; mat[2][1] = a21; mat[2][2] = a22;
}

//adition
Matrix3 Matrix3::operator+ (const Matrix3 & rhs) const
{
	return Matrix3( mat[0][0] + rhs.mat[0][0], mat[0][1] + rhs.mat[0][1], mat[0][2] + rhs.mat[0][2],			    
					mat[1][0] + rhs.mat[1][0], mat[1][1] + rhs.mat[1][1], mat[1][2] + rhs.mat[1][2],		  
					mat[2][0] + rhs.mat[2][0], mat[2][1] + rhs.mat[2][1], mat[2][2] + rhs.mat[2][2]);
}

//subraction
Matrix3 Matrix3::operator- (const Matrix3 & rhs) const
{
return Matrix3( mat[0][0] - rhs.mat[0][0], mat[0][1] - rhs.mat[0][1], mat[0][2] - rhs.mat[0][2],	  
				mat[1][0] - rhs.mat[1][0], mat[1][1] - rhs.mat[1][1], mat[1][2] - rhs.mat[1][2],
				mat[2][0] - rhs.mat[2][0], mat[2][1] - rhs.mat[2][1], mat[2][2] - rhs.mat[2][2]);
}

//multiplication
Matrix3 Matrix3::operator* (const Matrix3 & rhs) const
{
	Matrix3 result;

	result.mat[0][0] = rhs.mat[0][0] * mat[0][0] + rhs.mat[0][1] * mat[1][0] + rhs.mat[0][2] * mat[2][0];
	result.mat[0][1] = rhs.mat[0][0] * mat[0][1] + rhs.mat[0][1] * mat[1][1] + rhs.mat[0][2] * mat[2][1];
	result.mat[0][2] = rhs.mat[0][0] * mat[0][2] + rhs.mat[0][1] * mat[1][2] + rhs.mat[0][2] * mat[2][2];

	result.mat[1][0] = rhs.mat[1][0] * mat[0][0] + rhs.mat[1][1] * mat[1][0] + rhs.mat[1][2] * mat[2][0];
	result.mat[1][1] = rhs.mat[1][0] * mat[0][1] + rhs.mat[1][1] * mat[1][1] + rhs.mat[1][2] * mat[2][1];
	result.mat[1][2] = rhs.mat[1][0] * mat[0][2] + rhs.mat[1][1] * mat[1][2] + rhs.mat[1][2] * mat[2][2];

	result.mat[2][0] = rhs.mat[2][0] * mat[0][0] + rhs.mat[2][1] * mat[1][0] + rhs.mat[2][2] * mat[2][0];
	result.mat[2][1] = rhs.mat[2][0] * mat[0][1] + rhs.mat[2][1] * mat[1][1] + rhs.mat[2][2] * mat[2][1];
	result.mat[2][2] = rhs.mat[2][0] * mat[0][2] + rhs.mat[2][1] * mat[1][2] + rhs.mat[2][2] * mat[2][2];

	return result;
}

const Vector3 Matrix3::operator* (const Vector3 & rhs) const
{
	Vector3 result;

	result.x = mat[0][0] * rhs.x + mat[1][0] * rhs.y + mat[2][0] * rhs.z;
	result.y = mat[0][1] * rhs.x + mat[1][1] * rhs.y + mat[2][1] * rhs.z;
	result.z = mat[0][2] * rhs.x + mat[1][2] * rhs.y + mat[2][2] * rhs.z;

	return result;
}

const Matrix3 Matrix3::transpose()
{

	Matrix3 trans;

	trans.mat[0][0] = mat[0][0];
	trans.mat[0][1] = mat[1][0];
	trans.mat[0][2] = mat[2][0];

	trans.mat[1][0] = mat[0][1];
	trans.mat[1][1] = mat[1][1];
	trans.mat[1][2] = mat[2][1];

	trans.mat[2][0] = mat[0][2];
	trans.mat[2][1] = mat[1][2];
	trans.mat[2][2] = mat[2][2];


	return trans;
}

Matrix3::~Matrix3()
	{
		
	}	
		