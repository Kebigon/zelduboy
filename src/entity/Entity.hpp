#ifndef ENTITY_HPP
#define ENTITY_HPP

#include "../Location.hpp"

class Entity
{
	Location * location;

public:
	Entity(Location *location);
	Location * getLocation() const;
	virtual bool isPassable() const;
	virtual void update() = 0;
	virtual void draw() = 0;
};

#endif
