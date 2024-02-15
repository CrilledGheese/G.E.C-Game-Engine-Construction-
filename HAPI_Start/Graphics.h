#pragma once

#include <HAPI_lib.h>
using namespace HAPISPACE;

#include <unordered_map>
#include "RectangleC.h"

class Sprite;

class Graphics
{
public:
	~Graphics();

	bool Initialise(int width, int height);

	void clearScreen();

	//void setScreen(int width, int height, HAPI_TColour col);
	//void pixel(int width, int height, HAPI_TColour col, int x, int y);
	//void Blit(int sWidth, int sHeight, BYTE* text, int tWidth, int tHeight, int xPos, int yPos);
	//void TransBlit(int sWidth, int sHeight, BYTE* text, int tWidth, int tHeight, int xPos, int yPos);

	//BYTE* m_screen{ nullptr };

	bool CreateSprite(const std::string& filename, const std::string& name);
	void DrawSprite(const std::string& name, int xPos, int yPos);
	int SpriteWidth(const std::string& name)const;

private:
	BYTE* Screen = { nullptr };
	RectangleC ScreenRect { 0,0,0,0};
	int sWidth{ 0 };
	int sHeight{ 0 };
	std::unordered_map<std::string, Sprite*> m_spritemap;
	RectangleC GetSpriteRect(const std::string& spriteName) const;
	//BYTE* TxtPointer = { nullptr };
	//BYTE* ScreenPointer = { nullptr };

	//int TxtOffset = 0;
	//int ScreenOffset = 0;
};