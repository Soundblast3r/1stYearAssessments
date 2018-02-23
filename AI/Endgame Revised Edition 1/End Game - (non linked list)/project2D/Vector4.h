#pragma once
#include <math.h> 
class Vector4
{
public:
	//CONSTRUCTORS
	Vector4();
	Vector4(float xValue, float yValue, float zValue, float wValue);

	float x;
	float y;
	float z;
	float w;

	float Magnitude() const; //size of the vector
	float Dot(const Vector4 & v) const; //give you info about angle between vectors

	Vector4 Cross(const Vector4& rhs);

	Vector4 Normalized(); //normalized version of the vector
	void Normalize(); //alters x and y to be normalised

	bool Vector4::operator == (const Vector4 & rhs) const { return (x == rhs.x) && (y == rhs.y) && (z == rhs.z) && (w == rhs.w); }
	bool Vector4::operator != (const Vector4 & rhs) const { return (x != rhs.x) || (y != rhs.y) || (z != rhs.z) || (w != rhs.w);; }

	//VECTOR2 TO VECTOR2 OPERATIONS
	const Vector4 Vector4::operator + (const Vector4 & rhs) const { return Vector4(x + rhs.x, y + rhs.y, z + rhs.z, w + rhs.w); }
	const Vector4 Vector4::operator - (const Vector4 & rhs) const { return Vector4(x - rhs.x, y - rhs.y, z - rhs.z, w - rhs.w); }

	//VECTOR2 TO THIS OPERATIONS
	Vector4 & Vector4::operator += (const Vector4 & rhs) { x += rhs.x; y += rhs.y; z += rhs.z; w += rhs.w; return *this; }
	Vector4 & Vector4::operator -= (const Vector4 & rhs) { x -= rhs.x; y -= rhs.y; z -= rhs.z; w -= rhs.w; return *this; }

	//SCALER TO VECTOR2 OPERATIONS
	const Vector4 Vector4::operator * (float v) const { return Vector4(x * v, y * v, z * v, w * v); }

	//SCALER TO THIS OPERATIONS
	Vector4 & Vector4::operator *= (float v) { x *= v; y *= v; z *= v; w *= v; return *this; }

	explicit operator float*()
	{
		return &x;
	}
};

Vector4 operator* (float lhs, Vector4& rhs);
