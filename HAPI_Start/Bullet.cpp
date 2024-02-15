#include "Bullet.h"

void Bullet::Update()
{
	x += dirX;
	y += dirY;
}

void Bullet::getName(std::string name)
{
	spriteName = name;
}