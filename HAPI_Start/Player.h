#pragma once
#include "Entity.h"

class Player : public Entity
{
public:
	void Update() override final;
	void getSpriteName(std::string spriteName);
	sides GetSide() const override final { return sides::player; }
};