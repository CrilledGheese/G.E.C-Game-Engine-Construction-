#pragma once
#include "Entity.h"
#include "Vector2.h"

class Bullet : public Entity
{
private:
	int dirX;
	int dirY;
	sides side;
public:

	void Update() override;
	sides GetSide() const override { return side; }
	void getName(std::string name);
};