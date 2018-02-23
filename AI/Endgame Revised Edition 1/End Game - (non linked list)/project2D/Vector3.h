#pragma once

#include <math.h> 
class Vector3
{
public:
	//CONSTRUCTORS
	Vector3();
	Vector3(float xValue, float yValue, float zValue);

	float x;
	float y;
	float z;

	float Magnitude() const; //size of the vector
	float Dot(const Vector3 & v) const; //give you info about angle between vectors
	
	// need to implement Vector3.cross
	
	Vector3 Normalized(); //normalized version of the vector
	void Normalize(); //alters x and y to be normalised

	Vector3 Cross(const Vector3& rhs);

	bool Vector3::operator == (const Vector3 & rhs) const { return (x == rhs.x) && (y == rhs.y) && (z == rhs.z); }
	bool Vector3::operator != (const Vector3 & rhs) const { return (x != rhs.x) || (y != rhs.y) || (z != rhs.z); }

	//VECTOR2 TO VECTOR2 OPERATIONS
	const Vector3 Vector3::operator + (const Vector3 & rhs) const { return Vector3(x + rhs.x, y + rhs.y, z + rhs.z); }
	const Vector3 Vector3::operator - (const Vector3 & rhs) const { return Vector3(x - rhs.x, y - rhs.y, z - rhs.z); }

	//VECTOR2 TO THIS OPERATIONS
	Vector3 & Vector3::operator += (const Vector3 & rhs) { x += rhs.x; y += rhs.y; z += rhs.z; return *this; }
	Vector3 & Vector3::operator -= (const Vector3 & rhs) { x -= rhs.x; y -= rhs.y; z -= rhs.z; return *this; }

	//SCALER TO VECTOR2 OPERATIONS
	const Vector3 Vector3::operator * (float rhs) const { return Vector3(x * rhs, y * rhs, z * rhs); }

	//SCALER TO THIS OPERATIONS
	Vector3 & Vector3::operator *= (float rhs) { x *= rhs; y *= rhs; z *= rhs; return *this; }

	explicit operator float*()
	{
		return &x;
	}
};


Vector3 operator* (float lhs, Vector3& rhs);
