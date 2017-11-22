#include "MovableBlockGraphicsComponent.hpp"

#include <Sprites.h>
#include "globals.h"
#include "data/bitmaps.h"
#include "entity/MovableBlock.hpp"

void MovableBlockGraphicsComponent::draw(MovableBlock *block)
{
	uint16_t blockX = block->getLocation()->getX();
	uint16_t blockY = block->getLocation()->getY();

	int16_t displayBlockX = blockX - getDisplayStartX();
	int16_t displayBlockY = blockY - getDisplayStartY();

	Sprites::drawOverwrite(MAP_CANVAS_X + displayBlockX, MAP_CANVAS_Y + displayBlockY, tileset, 14);
}
