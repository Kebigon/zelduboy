#include "MapView.hpp"

#include "globals.h"
#include "../data/chunksdata.h"
#include "../data/bitmaps.h"


void MapView::handleInput()
{
	game->getPlayer()->update();
}

void MapView::draw()
{
	Player *player = game->getPlayer();

	drawMap(player);

	player->draw();
}

void MapView::drawMap(Player *player)
{
	Location *location = player->getLocation();
	Map *map = location->getMap();

	uint16_t displayStartX, displayStartY;

	switch (player->getHorizontalPosition())
	{
		case PlayerHorizontalPosition::LEFT:
			displayStartX = 0;
			break;
		case PlayerHorizontalPosition::CENTER:
			displayStartX = location->getX() - PLAYER_CENTER_POS_LEFT;
			break;
		case PlayerHorizontalPosition::RIGHT:
			displayStartX = map->getWidth() - MAP_CANVAS_WIDTH;
			break;
	}

	switch (player->getVerticalPosition())
	{
		case PlayerVerticalPosition::TOP:
			displayStartY = 0;
			break;
		case PlayerVerticalPosition::CENTER:
			displayStartY = location->getY() - PLAYER_CENTER_POS_TOP;
			break;
		case PlayerVerticalPosition::BOTTOM:
			displayStartY = map->getHeight() - MAP_CANVAS_HEIGHT;
			break;
	}

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
