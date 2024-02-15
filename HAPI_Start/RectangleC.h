#pragma once
#include <algorithm>

class RectangleC
{
public:
	int left{ 0 };
	int right{ 0 };
	int top{ 0 };
	int bottom{ 0 };

	RectangleC(int l, int r, int t, int b) : left(l), right(r), top(t), bottom(b) {}

	int Width() const { return right - left; }
	int Height() const { return bottom - top; }

	void Translate(int x, int y)
	{
		left += x;
		right += x;
		top += y;
		bottom += y;
	}

	void Clip(const RectangleC& other)
	{
		left = std::max(left, other.left);
		right = std::min(right, other.right);
		top = std::max(top, other.top);
		bottom = std::min(bottom, other.bottom);
	}
};