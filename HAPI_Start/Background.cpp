#include "Background.h"

void Background::Update()
{
	y++;

	if (y == 720) {
		y = -720;
	}
}

void Background::getSpriteName(std::string name)
{
	spriteName = name;
}

void Background::overridePos()
{
	y = -720;
}
