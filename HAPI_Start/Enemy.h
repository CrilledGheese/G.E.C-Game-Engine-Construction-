#pragma once
#include "Entity.h"

class Enemy : public Entity
{
public:
	void Update() override final;
	virtual ~Enemy() {}
	void getName(std::string name);
	sides GetSide() const override final { return sides::enemy; }
};