#include "Matrix2.h"
#include <iostream>
#include "Math.h"


Matrix2::Matrix2()
{
	mat[0][0] = 1; mat[0][1] = 0;
	mat[1][0] = 0; mat[1][1] = 1;
}

Matrix2::Matrix2(float a00, float a01, float a10, float a11)
{
	mat[0][0] = a00; mat[0][1] = a01;
	mat[1][0] = a10; mat[1][1] = a11;
}

//matrix addition (operator overload similar to vector addition)
const Matrix2 Matrix2::operator+ (const Matrix2 & rhs) const 
{ 
	return Matrix2(mat[0][0] + rhs.mat[0][0], mat[0][1] + rhs.mat[0][1], 
				   mat[1][0] + rhs.mat[1][0], mat[1][1] + rhs.mat[1][1]); 
}

//matrix subtraction
const Matrix2 Matrix2::operator- (const Matrix2 & rhs) const 
{ 
	return Matrix2(mat[0][0] - rhs.mat[0][0], mat[0][1] - rhs.mat[0][1],
				   mat[1][0] - rhs.mat[1][0], mat[1][1] - rhs.mat[1][1]);
}

//multiplication
const Matrix2 Matrix2::operator* (const Matrix2 & rhs) const
{
	Matrix2 result;

	result.mat[0][0] = mat[0][0] * rhs.mat[0][0] + mat[0][1] * rhs.mat[1][0];
	result.mat[0][1] = mat[0][0] * rhs.mat[0][1] + mat[0][1] * rhs.mat[1][1];
	result.mat[1][0] = mat[1][0] * rhs.mat[0][0] + mat[1][1] * rhs.mat[1][0];
	result.mat[1][1] = mat[1][0] * rhs.mat[0][1] + mat[1][1] * rhs.mat[1][1];
	
	return result;

	//mat is m1,
	//rhs.mat is m2
}

const Vector2 Matrix2::operator* (const Vector2 & rhs) const
{
	Vector2 result;

	result.x = mat[0][0] * rhs.x + mat[1][0] * rhs.y;
	result.y = mat[0][1] * rhs.x + mat[1][1] * rhs.y;

	return result;
}

const Matrix2 Matrix2::transpose()
{
	Matrix2 trans;

	trans.mat[0][0] = mat[0][0];
	trans.mat[0][1] = mat[1][0];
	trans.mat[1][0] = mat[0][1];
	trans.mat[1][1] = mat[1][1];

	return trans;
}

Matrix2::~Matrix2()
{

}