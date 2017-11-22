#ifndef ENTITY_HPP
#define ENTITY_HPP

#include "Location.hpp"
#include "EntityType.hpp"
#include <Arduboy2.h>

class Entity
{
	Location * location;

public:
	Entity(Location *location);
	Location * getLocation() const;
	Rect getCollisionBox() const;
	bool collideWith(Rect otherCollisionBox) const;
	virtual bool isPassable() const;
	virtual void update() = 0;
	virtual void draw() = 0;
	virtual EntityType getType() const = 0;
};

#endif
