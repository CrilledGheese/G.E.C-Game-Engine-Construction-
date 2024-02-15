#include "Entity.h"
#include "Graphics.h"
#include "Sprite.h"

void Entity::Render(Graphics* graphics)
{
	graphics->DrawSprite("Player", random_position + x, y + random_position);
}

bool Entity::IsEnemy(Entity* other) const
{
	//If eiAther side is neutral then you cant be the enemy of it
	if (GetSide() == sides::neutral)
		return false;
	if (other->GetSide() == sides::neutral)
		return false;

	//If the other entity is on the same side as this one then they arent enemies
	if (other->GetSide() == GetSide())
		return false;


	return true;

}