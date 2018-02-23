#include "Vector3.h"

//CONSTRUCTORS
Vector3::Vector3()
{
}

Vector3::Vector3(float xValue, float yValue, float zValue)
{
	x = xValue;
	y = yValue;
	z = zValue;
}

float Vector3::Magnitude() const
{
	///return the size of the vector

	// magnitude is the size of the line, which is calculated by having the length of x from point 1 to point 2, and the length of y from point 1 to point to
	// drawing a hypothetical trangle, from here, with A being the opposite, b being the adjacent and c being the hypotenuse we can calculate the length of the
	// hypotenuse which is the magnitude or distance between point 1 and point 2
	// mathematical equation is: a^2 + b^2 = c^2

	float m = sqrt(x*x + y*y + z*z);
	return m;

}

float Vector3::Dot(const Vector3 & rhs) const
{
	return x * rhs.x + y * rhs.y + z * rhs.z;
}

void Vector3::Normalize()
{
	///if the magnitude/length of the vector isn't 0, we divide the x and y by it's size
	if (Magnitude() != 0)
	{
		float mag = Magnitude();
		x /= mag;
		y /= mag;
		z /= mag;
	}

	// normalising a vector is modifying the vector so that its hypotenuse or Magnitude is equal to 1
	// normalising a vector can also apply the use of scaling the vector.
}

Vector3 Vector3::Cross(const Vector3 & rhs)
{
	Vector3 result;

	result.x = y * rhs.z - z * rhs.y;
	result.y = z * rhs.x - x * rhs.z;
	result.z = x * rhs.y - y * rhs.x;

	return result;
}

Vector3 Vector3::Normalized()
{
	///create a new vector
	Vector3 newVec;

	//copy x and y into the new vector
	newVec.x = x;
	newVec.y = y;
	newVec.z = z;

	//normalize new vector using your Normalize function. (newVector.Normalize())
	///return newVector
	newVec.Normalize();
	return newVec;
}

Vector3 operator* (float lhs, Vector3& rhs)
{
	return Vector3(rhs.x * lhs, rhs.y * lhs, rhs.z * lhs);
}

