#include "Game.hpp"

#include "globals.h"
#include "chunksdata.h"
#include "bitmaps.h"

void Game::handleInput()
{
	player.isMoving = false;

	if (arduboy.pressed(LEFT_BUTTON))
	{
		player.x--;
		player.direction = LEFT;
		player.isMoving = true;
	}
	else if (arduboy.pressed(RIGHT_BUTTON))
	{
		player.direction = RIGHT;
		player.x++;
		player.isMoving = true;
	}

	if (arduboy.pressed(UP_BUTTON))
	{
		player.direction = UP;
		player.y--;
		player.isMoving = true;
	}
	else if (arduboy.pressed(DOWN_BUTTON))
	{
		player.direction = DOWN;
		player.y++;
		player.isMoving = true;
	}
}

void Game::display()
{
	// first we clear our screen to black
	arduboy.clear();

	draw(mapHouse, player);

	player.draw();

	arduboy.display();
}

void Game::draw(Map & currentMap, Player & player)
{
	uint8_t mapWidth = currentMap.getWidth();
	uint8_t mapHeight = currentMap.getHeight();

	int16_t displayStartTileX = pixelToTileCoord(player.x - 56);
	int16_t displayStartTileY = pixelToTileCoord(player.y - 24);

	int16_t displayStopTileX = pixelToTileCoord(player.x + 56 + 16 - 1);
	int16_t displayStopTileY = pixelToTileCoord(player.y + 24 + 16 - 1);

	for (int16_t tileX = displayStartTileX; tileX <= displayStopTileX; tileX++)
	{
		for (int16_t tileY = displayStartTileY; tileY <= displayStopTileY; tileY++)
		{
			if (tileX < 0 || tileX >= mapWidth || tileY < 0 || tileY >= mapHeight)
				continue; // Do nothing

			int16_t x = (tileX - displayStartTileX) * TILE_SIZE - (player.x + 8) % TILE_SIZE;
			int16_t y = (tileY - displayStartTileY) * TILE_SIZE - (player.y + 8) % TILE_SIZE;

			uint8_t tile = currentMap.getTile(tileX, tileY);

			Sprites::drawSelfMasked(x, y, tileset, tile);
		}
	}
}

int16_t Game::pixelToTileCoord(int16_t pixelCoord)
{
	return pixelCoord >> 4;
}
