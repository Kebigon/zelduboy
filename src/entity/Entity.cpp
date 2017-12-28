#include "Entity.hpp"

#include "globals.h"

Entity::Entity(uint8_t spawnX, uint8_t spawnY)
	: spawnX(spawnX)
	, spawnY(spawnY)
{}

void Entity::spawn() {
	if (state == nullptr)
		state = new EntityState();
}

void Entity::despawn()
{
	delete state;
	state = nullptr;
}

Location * Entity::getLocation() const
{
	return state != nullptr ? state->getLocation() : nullptr;
}

// TODO: At the moment all entites are 16*16 for test, to change in the future
Rect Entity::getCollisionBox() const
{
	Rect collisionBox = { location->getX(), location->getY(), 16, 16 };
	return collisionBox;
}

bool Entity::collideWith(Rect otherCollisionBox) const
{
	return arduboy.collide(getCollisionBox(), otherCollisionBox);
}

bool Entity::isPassable() const
{
	return true;
}
