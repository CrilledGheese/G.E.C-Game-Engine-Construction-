#pragma once
#include <cmath>

class Vector2
{
public:
	float x{ 0 };
	float y{ 0 };

	Vector2() = default;
	Vector2(float newX, float newY) : x(newX), y(newY) {}


	float Length() const
	{
		return sqrt(x * x + y * y);
	}

	void NormaliseInPlace()
	{
		float len = Length();

		if (len == 0)
			return;

		x /= len;
		y /= len;
	}

	float dot(const Vector2& other) const
	{
		return x * other.x + y * other.y;
	}

	float cross(const Vector2& other) const
	{
		return x * other.y - y * other.x;
	}
};