#include "Vector4.h"

//CONSTRUCTORS
Vector4::Vector4()
{
	x = 0.0f;
	y = 0.0f;
	z = 0.0f;
	w = 0.0f;
}

Vector4::Vector4(float xValue, float yValue, float zValue, float wValue)
{
	x = xValue;
	y = yValue;
	z = zValue;
	w = wValue;
}

float Vector4::Magnitude() const
{
	///return the size of the vector

	// magnitude is the size of the line, which is calculated by having the length of x from point 1 to point 2, and the length of y from point 1 to point to
	// drawing a hypothetical trangle, from here, with A being the opposite, b being the adjacent and c being the hypotenuse we can calculate the length of the
	// hypotenuse which is the magnitude or distance between point 1 and point 2
	// mathematical equation is: a ^2 + b^2 = c ^2

	float m = sqrt(x*x + y*y + z*z + w*w);
	return m;

}

float Vector4::Dot(const Vector4 & rhs) const
{
	return x * rhs.x + y * rhs.y + z * rhs.z + w * rhs.w;;
}

void Vector4::Normalize()
{
	///if the magnitude/length of the vector isn't 0, we divide the x and y by it's size
	if (Magnitude() != 0)
	{
		float mag = Magnitude();
		x /= mag;
		y /= mag;
		z /= mag;
		//w /= mag;
	}

	// normalising a vector is modifying the vector so that its hypotenuse or Magnitude is equal to 1
	// normalising a vector can also apply the use of scaling the vector.
}

Vector4 Vector4::Normalized()
{
	///create a new vector
	Vector4 newVec;

	//copy x and y into the new vector
	newVec.x = x;
	newVec.y = y;
	newVec.z = z;
	newVec.w = w;

	//normalize new vector using your Normalize function. (newVector.Normalize())
	///return newVector
	newVec.Normalize();
	return newVec;
}

Vector4 Vector4::Cross(const Vector4 & rhs)
{
	Vector4 result;

	result.x = y * rhs.z - z * rhs.y;
	result.y = z * rhs.x - x * rhs.z;
	result.z = x * rhs.y - y * rhs.x;

	return result;
}

Vector4 operator* (float lhs, Vector4& rhs)
{
	return Vector4(rhs.x * lhs, rhs.y * lhs, rhs.z * lhs, rhs.w);
}
