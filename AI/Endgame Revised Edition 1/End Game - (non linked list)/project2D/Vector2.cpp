#include "Vector2.h"

//CONSTRUCTORS
Vector2::Vector2()
{
	x = 0.0f;
	y = 0.0f;
}

Vector2::Vector2(float xValue, float yValue)
{
	x = xValue;
	y = yValue;
}

float Vector2::Magnitude() const
{
	///return the size of the vector

	// magnitude is the size of the line, which is calculated by having the length of x from point 1 to point 2, and the length of y from point 1 to point to
	// drawing a hypothetical trangle, from here, with A being the opposite, b being the adjacent and c being the hypotenuse we can calculate the length of the
	// hypotenuse which is the magnitude or distance between point 1 and point 2
	// mathematical equation is: a ^2 + b^2 = c ^2

	float m = sqrt(x*x + y*y);
	return m;

} 

float Vector2::Dot(const Vector2 & rhs) const
{
	return x * rhs.x + y * rhs.y;
}

void Vector2::Normalize()
{
	//if the magnitude/length of the vector isn't 0, we divide the x and y by it's size
	if (Magnitude() != 0)
	{
		float mag = Magnitude();
		x /= mag;
		y /= mag;
	}

	// normalising a vector is modifying the vector so that its hypotenuse or Magnitude is equal to 1
	// normalising a vector can also apply the use of scaling the vector.
}

Vector2 Vector2::Normalized()
{
	///create a new vector
	Vector2 newVec;

	//copy x and y into the new vector
	newVec.x = x;
	newVec.y = y;

	//normalize new vector using your Normalize function. (newVector.Normalize())
	///return newVector
	newVec.Normalize();
	return newVec;
}

Vector2 operator*(float lhs, Vector2& rhs)
{
	return rhs*lhs;
}