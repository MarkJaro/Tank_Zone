#pragma once
#ifndef VECTOR3_H
#define VECTOR3_H

#include <cmath>
#include <iostream>

#define real_sqrt sqrtf
typedef float real;

class Vector3
{
public:
	real x;
	real y;
	real z;

	real pad; // it can be deleted, added for performance

public:
	Vector3() : x(), y(), z() {}

	Vector3(const real x, const real y, const real z) : x(x), y(y), z(z) {}

	void invert()
	{
		x = -x;
		y = -y;
		z = -z;
	}

	real magnitude() const
	{
		real num = x * x + y * y + z * z;
		real num2 = sqrtf(num);
		return real_sqrt(num);
	}

	real squareMagnitude() const
	{
		return x * x + y * y + z * z;
	}

	void normilize()
	{
		real d = magnitude();

		if (d > 0)
		{
			//(*this) *= ((real)1) / 1;
			x *= ((real)1) / d;
			y *= ((real)1) / d;
			z *= ((real)1) / d;

		}
	}
	void operator*=(const real value)
	{
		x *= value;
		y *= value;
		z *= value;
	}

	Vector3 operator*(const real value) const
	{
		return Vector3(x * value, y * value, z * value);
	}

	void operator+=(const Vector3& vec)
	{
		x += vec.x;
		y += vec.y;
		z += vec.z;
	}

	Vector3 operator+(const Vector3& vec) const
	{
		return Vector3(x + vec.x, y + vec.y, z + vec.z);
	}

	void operator-=(const Vector3& vec)
	{
		x -= vec.x;
		y -= vec.y;
		z -= vec.z;
	}

	Vector3 operator-(const Vector3& vec) const
	{
		return Vector3(x - vec.x, y - vec.y, z - vec.z);
	}

	void addScaledVector(const Vector3& vec, real scale)
	{
		x += vec.x * scale;
		y += vec.y * scale;
		z += vec.z * scale;
	}

	Vector3 componentProduct(const Vector3& vec) const
	{
		return Vector3(x * vec.x, y * vec.y, z * vec.z);
	}

	void componentProductUpdate(const Vector3& vec)
	{
		x *= vec.x;
		y *= vec.y;
		z *= vec.z;
	}

	real scalarProduct(const Vector3& vec) const
	{
		return x * vec.x + y * vec.y + z * vec.z;
	}

	real operator *(const Vector3& vec) const
	{
		return scalarProduct(vec);
	}

	Vector3 vectorProduct(const Vector3 vec) const
	{
		return Vector3(y * vec.z - z * vec.y,
					   z * vec.x - x * vec.z,
					   x * vec.y - y * vec.x);
	}

	void operator %=(const Vector3& vec)
	{
		(*this) = vectorProduct(vec);
	}

	Vector3 operator %(const Vector3& vec)
	{
		return Vector3(y * vec.z - z * vec.y,
					   z * vec.x - x * vec.z,
					   x * vec.y - y * vec.x);
	}

	// My custom functions

	void test()
	{
		std::cout << "x = " << x << std::endl;
		std::cout << "y = " << y << std::endl;
		std::cout << "z = " << z << std::endl;
	}
	
	void checkAccelerationLimit()
	{
		//float value = 70;
		//float value = 2;
		float value = 2;

		if (x > value) x = value;
		if (y > value) y = value;
		if (z > value) z = value;

		if (x < -value) x = -value;
		if (y < -value) y = -value;
		if (z < -value) z = -value;

		/*
		int value1 = value / 2;
		if (x > 0 & x < value1) x = value1;
		if (y > 0 & y < value1) y = value1;
		if (z > 0 & z < value1) z = value1;

		if (x < 0 & x > -value1) x = -value1;
		if (y < 0 & y > -value1) y = -value1;
		if (z < 0 & z > -value1) z = -value1;
		*/








	}

};
#endif