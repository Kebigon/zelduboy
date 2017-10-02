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

	draw(map_house, MAP_HOUSE_WIDTH, player);

	player.draw();

	arduboy.display();
}

void Game::draw(const uint8_t currentChunk[], uint8_t chunkWidth,
				Player & player)
{
	int16_t displayStartTileX = pixelToTileCoord(player.x - 56);
	int16_t displayStartTileY = pixelToTileCoord(player.y - 24);

	int16_t displayStopTileX = pixelToTileCoord(player.x + 56 + 16 - 1);
	int16_t displayStopTileY = pixelToTileCoord(player.y + 24 + 16 - 1);

	for (int16_t tileX = displayStartTileX; tileX <= displayStopTileX; tileX++)
	{
		for (int16_t tileY = displayStartTileY; tileY <= displayStopTileY; tileY++)
		{
			if (tileX < 0 || tileX >= MAP_HOUSE_WIDTH || tileY < 0 || tileY >= MAP_HOUSE_HEIGHT)
				continue; // Do nothing

			uint16_t tileIdx = tileY * chunkWidth + tileX;

			int16_t x = (tileX - displayStartTileX) * TILE_SIZE - (player.x + 8) % TILE_SIZE;
			int16_t y = (tileY - displayStartTileY) * TILE_SIZE - (player.y + 8) % TILE_SIZE;

			uint8_t tile =pgm_read_byte_near(map_house + tileIdx);

			Sprites::drawSelfMasked(x, y, tileset, tile);
		}
	}
}

int16_t Game::pixelToTileCoord(int16_t pixelCoord)
{
	return pixelCoord >> 4;
}
