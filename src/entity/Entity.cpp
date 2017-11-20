#include "Entity.hpp"

#include "globals.h"

Entity::Entity(Location * location)
	: location(location)
{}

Location * Entity::getLocation() const
{
	return location;
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
