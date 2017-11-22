#include "MovableBlock.hpp"

MovableBlock::MovableBlock(Location *location)
	: Entity(location)
{}

EntityType MovableBlock::getType() const
{
	return EntityType::MOVABLE_BLOCK;
}

bool MovableBlock::isPassable() const
{
	return false;
}

void MovableBlock::update()
{
	physicsComponent.update(this);
}

void MovableBlock::draw()
{
	graphicsComponent.draw(this);
}

bool MovableBlock::push(int8_t velocityX, int8_t velocityY)
{
	if (!physicsComponent.canBePushed(this, velocityX, velocityY))
		return false;

	if (velocityX != 0)
		getLocation()->updateX(velocityX);
	if (velocityY != 0)
		getLocation()->updateY(velocityY);

	return true;
}
