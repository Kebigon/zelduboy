#include "MovableBlock.hpp"

#include <Sprites.h>
#include "data/bitmaps.h"
#include "globals.h"

MovableBlock::MovableBlock(Location *location)
	: Entity(location)
{}

void MovableBlock::update()
{}

void MovableBlock::draw()
{
	graphicsComponent.draw(this);
}
