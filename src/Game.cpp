#include "Game.hpp"

#include "globals.h"
#include "chunksdata.h"
#include "bitmaps.h"

Game::Game()
{
	Location * loc = new Location(mapHouse, 16, 16);
	player = new Player(loc);
}

void Game::handleInput()
{
	player->isMoving = false;

	if (arduboy.pressed(LEFT_BUTTON))
	{
		player->getLocation()->updateX(-1);
		player->direction = Direction::LEFT;
		player->isMoving = true;
	}
	else if (arduboy.pressed(RIGHT_BUTTON))
	{
		player->direction = Direction::RIGHT;
		player->getLocation()->updateX(1);
		player->isMoving = true;
	}

	if (arduboy.pressed(UP_BUTTON))
	{
		player->direction = Direction::UP;
		player->getLocation()->updateY(-1);
		player->isMoving = true;
	}
	else if (arduboy.pressed(DOWN_BUTTON))
	{
		player->direction = Direction::DOWN;
		player->getLocation()->updateY(1);
		player->isMoving = true;
	}
}

void Game::display()
{
	// first we clear our screen to black
	arduboy.clear();

	drawMap();

	player->draw();

	arduboy.display();
}

void Game::drawMap()
{
	Location * playerLocation = player->getLocation();
	uint16_t playerX = playerLocation->getX();
	uint16_t playerY = playerLocation->getY();

	// TODO: find why this dos not return the right instance
	// Map map = playerLocation->getMap();
	Map map = mapHouse;

	uint16_t displayStartX, displayStartY;

	switch (player->getHorizontalPosition())
	{
		case PlayerHorizontalPosition::LEFT:
			displayStartX = 0;
			break;
		case PlayerHorizontalPosition::CENTER:
			displayStartX = playerX - PLAYER_CENTER_POS_LEFT;
			break;
		case PlayerHorizontalPosition::RIGHT:
			displayStartX = map.getWidth() - SCREEN_WIDTH;
			break;
	}

	switch (player->getVerticalPosition())
	{
		case PlayerVerticalPosition::TOP:
			displayStartY = 0;
			break;
		case PlayerVerticalPosition::CENTER:
			displayStartY = playerY - PLAYER_CENTER_POS_TOP;
			break;
		case PlayerVerticalPosition::BOTTOM:
			displayStartY = map.getHeight() - SCREEN_HEIGHT;
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

			uint8_t tile = map.getTile(tileX, tileY);

			Sprites::drawSelfMasked(x, y, tileset, tile);
		}
	}
}
