#pragma once

#include "RectangleC.h"
#include <HAPI_lib.h>
using namespace HAPISPACE;

class Sprite
{
private:
	int sWidth{ 1024 };
	int sHeight{ 768 };
	int m_tWidth;
	int m_tHeight;
	int x;
	int y;

	BYTE* m_texture{ nullptr };
	BYTE* TxtPointer = { nullptr };
	BYTE* ScreenPointer = { nullptr };

public:
	virtual ~Sprite();
	bool Create(const std::string& filename);
	void TransDraw(BYTE* screen, RectangleC screenRC, int sX, int sY);
	int GetWidth() const { return m_tWidth; }
	int GetHeight() const { return m_tHeight; }
};