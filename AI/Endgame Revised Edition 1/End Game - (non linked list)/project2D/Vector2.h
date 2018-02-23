#pragma once

#include <math.h> 
class Vector2
{
public:
	//CONSTRUCTORS
	Vector2();
	Vector2(float xValue, float yValue);

	float x;
	float y;
	
	float Magnitude() const; //size of the vector
	float Dot(const Vector2 & rhs) const; //give you info about angle between vectors


	Vector2 Normalized(); //normalized version of the vector
	void Normalize(); //alters x and y to be normalised

	bool Vector2::operator == (const Vector2 & rhs) const { return (x == rhs.x) && (y == rhs.y); }
	bool Vector2::operator != (const Vector2 & rhs) const { return (x != rhs.x) || (y != rhs.y); }

	//VECTOR2 TO VECTOR2 OPERATIONS (a + b)
	const Vector2 Vector2::operator + (const Vector2 & rhs) const { return Vector2(x + rhs.x, y + rhs.y); }
	const Vector2 Vector2::operator - (const Vector2 & rhs) const { return Vector2(x - rhs.x, y - rhs.y); }

	//VECTOR2 TO THIS OPERATIONS
	Vector2 & Vector2::operator += (const Vector2 & rhs) { x += rhs.x; y += rhs.y; return *this; }
	Vector2 & Vector2::operator -= (const Vector2 & rhs) { x -= rhs.x; y -= rhs.y; return *this; } 

	//SCALER TO VECTOR2 OPERATIONS
	const Vector2 Vector2::operator * (float rhs) const { return Vector2(x * rhs, y * rhs); }

	//SCALER TO THIS OPERATIONS
	Vector2 & Vector2::operator *= (float rhs) { x *= rhs; y *= rhs; return *this; }

	explicit operator float*()
	{
		return &x;
	}
};

Vector2 operator*(float lhs, Vector2& rhs);
