#include "Graphics.h"
#include "Sprite.h"
#include "RectangleC.h"

Graphics::~Graphics()
{
	for (auto& p : m_spritemap)
		delete p.second;
}

bool Graphics::Initialise(int width, int height)
{
	if (!HAPI.Initialise(width, height, "Cheese"))
		return false;

	sWidth = width;
	sHeight = height;

	ScreenRect.left = 0;
	ScreenRect.right = sWidth;
	ScreenRect.top = 0;
	ScreenRect.bottom = sHeight;


	Screen = HAPI.GetScreenPointer();
	return true;
}


void Graphics::clearScreen()
{
	memset(Screen, 0, sWidth * sHeight * 4);
}


//void Graphics::setScreen(int width, int height, HAPI_TColour col)
//{
//	for (int x = 0; x < width * height * 4; x += 4)
//	{
//		memcpy(Screen + x, &col, width);
//	}
//}
//
//void Graphics::pixel(int width, int height, HAPI_TColour col, int x, int y)
//{
//	if ((y < height && y > 0) && (x < width && x > 0))
//	{
//		memcpy(Screen + ((x + y * width) * 4), &col, 4);
//	}
//}

bool Graphics::CreateSprite(const std::string& filename, const std::string& name)
{
	Sprite* newSprite = new Sprite;
	if (!newSprite->Create(filename))
	{
		return false;
	}

	m_spritemap[name] = newSprite;

	return true;
}

void Graphics::DrawSprite(const std::string& name, int xPos, int yPos)
{
	// TOOD: look up sprite in map then call its draw function

	auto s = m_spritemap.find(name);

	if (s != m_spritemap.end())
	{
		m_spritemap[name]->TransDraw(Screen, ScreenRect, xPos, yPos);
	}
	else
	{
		HAPI.UserMessage("Data sucks", "Data sucks good");
		return;
	}
}

int Graphics::SpriteWidth(const std::string& name) const
{
	//Need to use at because the function is constant which means it cant be  modified
	return m_spritemap.at(name)->GetWidth();

}

RectangleC Graphics::GetSpriteRect(const std::string& name) const
{
	std::unordered_map<std::string, Sprite*>::iterator it;
	Sprite* newSprite = new Sprite;

	float m_width = m_spritemap.at(name)->GetWidth();
	float m_height = m_spritemap.at(name)->GetHeight();

	RectangleC newRectangle(0, m_width, 0, m_height);

	return newRectangle;
}



































//// TODO: move to sprite draw
//void Graphics::Blit(int sWidth, int sHeight, BYTE* text, int tWidth, int tHeight, int xPos, int yPos)
//{
//	TxtPointer = text;
//	ScreenPointer = Screen + (xPos + yPos * sWidth) * 4;
//
//	for (int y = 0; y < tHeight; y++)
//	{
//		memcpy(ScreenPointer, TxtPointer, tWidth * 4);
//
//		TxtPointer += tWidth * 4;
//		ScreenPointer += sWidth * 4;
//	}
//}
//
//// TODO: move to sprite draw
//void Graphics::TransBlit(int sWidth, int sHeight, BYTE* text, int tWidth, int tHeight, int xPos, int yPos)
//{
//	TxtPointer = text;
//	ScreenPointer = Screen;
//	ScreenOffset = (xPos + yPos * sWidth) * 4;
//	TxtOffset = 0;
//
//	int EndOFLineScreenIncrement = (sWidth - tWidth) * 4;
//
//	for (int y = 0; y < tHeight; y++)
//	{
//		for (int x = 0; x < tWidth; x++)
//		{
//			BYTE sa = TxtPointer[TxtOffset + 3];
//			if (sa != 0)
//			{
//				BYTE Blue = TxtPointer[TxtOffset];
//				BYTE Green = TxtPointer[TxtOffset + 1];
//				BYTE Red = TxtPointer[TxtOffset + 2];
//
//				//float Mod = sa / 255.0f;
//
//				ScreenPointer[ScreenOffset] = ScreenPointer[ScreenOffset] + ((sa * (Blue - ScreenPointer[ScreenOffset])) >> 8);
//				ScreenPointer[ScreenOffset + 1] = ScreenPointer[ScreenOffset + 1] + ((sa * (Green - ScreenPointer[ScreenOffset + 1])) >> 8);
//				ScreenPointer[ScreenOffset + 2] = ScreenPointer[ScreenOffset + 2] + ((sa * (Red - ScreenPointer[ScreenOffset + 2])) >> 8);
//			}
//			ScreenOffset += 4;
//			TxtOffset += 4;
//		}
//		ScreenPointer += EndOFLineScreenIncrement;
//	}
//}