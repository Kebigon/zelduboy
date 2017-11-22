#include "MovableBlockPhysicsComponent.hpp"

#include "entity/MovableBlock.hpp"

void MovableBlockPhysicsComponent::update(MovableBlock *block)
{}

bool MovableBlockPhysicsComponent::canBePushed(MovableBlock *block, int8_t velocityX, int8_t velocityY)
{
	return checkMapPassability(block->getLocation(), velocityX, velocityY);
}
