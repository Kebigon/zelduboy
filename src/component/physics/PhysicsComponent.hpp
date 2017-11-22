#ifndef PHYSICS_COMPONENT_HPP
#define PHYSICS_COMPONENT_HPP

#include <stdint.h>
#include <Arduboy2.h>
#include "Location.hpp"

class PhysicsComponent
{
protected:
	static bool checkMapPassability(Location *location, int8_t velocityX, int8_t velocityY);
	static bool checkEntityCollisions(Rect playerCollisionBox, int8_t velocityX, int8_t velocityY);
};

#endif
