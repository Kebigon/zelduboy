#include "DroppedItemGraphicsComponent.hpp"

#include "globals.h"
#include "data/bitmaps.h"
#include "entity/DroppedItem.hpp"

void DroppedItemGraphicsComponent::draw(DroppedItem *item)
{
	uint16_t itemX = item->getLocation()->getX();
	uint16_t itemY = item->getLocation()->getY();

	uint8_t displayItemX = itemX - getDisplayStartX();
	uint8_t displayItemY = itemY - getDisplayStartY();

	uint8_t frame = static_cast<uint8_t>(item->getType());

	Sprites::drawPlusMask(MAP_CANVAS_X + displayItemX, MAP_CANVAS_Y + displayItemY, items_plus_mask, frame);
}
