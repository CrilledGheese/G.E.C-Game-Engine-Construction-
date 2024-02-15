#pragma once
#include <string>
class Graphics;

enum class sides
{
	neutral,
	player,
	enemy
};

class Entity
{
private:
	std::string m_spritename;

protected:
	int x{0};
	int y{0};
	int random_position = (rand() % 200);
	std::string spriteName{ "nullptr " };

public:
	int getX() const;
	int getY() const;

	virtual ~Entity() {}
	virtual void Update() = 0;
	void Render(Graphics* graphics);
	virtual sides GetSide() const = 0;
	bool IsEnemy(Entity* other) const;
	bool checkCollision(Entity* other, Graphics* Graphics) const;
};