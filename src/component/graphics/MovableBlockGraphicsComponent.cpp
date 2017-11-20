#include "MovableBlockGraphicsComponent.hpp"

#include <Sprites.h>
#include "globals.h"
#include "data/bitmaps.h"
#include "entity/MovableBlock.hpp"

void MovableBlockGraphicsComponent::draw(MovableBlock *block)
{
	uint16_t blockX = block->getLocation()->getX();
	uint16_t blockY = block->getLocation()->getY();

	uint8_t displayBlockX = blockX - getDisplayStartX();
	uint8_t displayBlockY = blockY - getDisplayStartY();

	Sprites::drawOverwrite(MAP_CANVAS_X + displayBlockX, MAP_CANVAS_Y + displayBlockY, tileset, 14);
}
