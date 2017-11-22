#include "MovableBlock.hpp"

#include <Sprites.h>
#include "data/bitmaps.h"
#include "globals.h"

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
{}

void MovableBlock::draw()
{
	graphicsComponent.draw(this);
}

bool MovableBlock::push(int8_t velocityX, int8_t velocityY)
{
	if (velocityX != 0)
		getLocation()->updateX(velocityX);
	if (velocityY != 0)
		getLocation()->updateY(velocityY);
	return true;
}
