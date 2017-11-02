#include "TilesGraphicsComponent.hpp"

#include "../globals.h"
#include "../data/bitmaps.h"

void TilesGraphicsComponent::draw()
{
	Location *location = game->getPlayer()->getLocation();
	Map *map = location->getMap();

	uint16_t displayStartX = getDisplayStartX(), displayStartY = getDisplayStartY();



	uint8_t displayStartTileX = displayStartX >> 4; // displayStartX / 16
	uint8_t displayStartTileY = displayStartY >> 4; // displayStartY / 16

	uint8_t displayStopTileX = (displayStartX + 127)  >> 4;
	uint8_t displayStopTileY = (displayStartY + 63)  >> 4;

	for (int16_t tileX = displayStartTileX; tileX <= displayStopTileX; tileX++)
	{
		for (int16_t tileY = displayStartTileY; tileY <= displayStopTileY; tileY++)
		{
			int16_t x = (tileX - displayStartTileX) * TILE_SIZE - (displayStartX) % TILE_SIZE;
			int16_t y = (tileY - displayStartTileY) * TILE_SIZE - (displayStartY) % TILE_SIZE;

			uint8_t tile = map->getTile(tileX, tileY);

			Sprites::drawSelfMasked(MAP_CANVAS_X + x, MAP_CANVAS_Y + y, tileset, tile);
		}
	}
}
