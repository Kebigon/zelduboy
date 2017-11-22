#ifndef MOVABLE_BLOCK_PHYSICS_COMPONENT_HPP
#define MOVABLE_BLOCK_PHYSICS_COMPONENT_HPP

#include "PhysicsComponent.hpp"

#include <stdint.h>

class MovableBlock;

class MovableBlockPhysicsComponent : public PhysicsComponent
{
public:
	void update(MovableBlock *block);
	bool canBePushed(MovableBlock *block, int8_t velocityX, int8_t velocityY);
};

#endif
