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
	int8_t moveX = 0, moveY = 0;

	if (arduboy.pressed(LEFT_BUTTON))
	{
		player->direction = Direction::LEFT;
		moveX = -1;
	}
	else if (arduboy.pressed(RIGHT_BUTTON))
	{
		player->direction = Direction::RIGHT;
		moveX = 1;
	}

	if (arduboy.pressed(UP_BUTTON))
	{
		player->direction = Direction::UP;
		moveY = -1;
	}
	else if (arduboy.pressed(DOWN_BUTTON))
	{
		player->direction = Direction::DOWN;
		moveY = 1;
	}

	if (moveX != 0 || moveY != 0)
	{
		player->isMoving = true;

		Location *location = player->getLocation();
		bool checkPassableX = location->getX() % TILE_SIZE == 0;
		bool checkPassableY = location->getY() % TILE_SIZE == 0;

		if (checkPassableX || checkPassableY)
		{
			uint8_t newTileX = (location->getX() + moveX) >> 4;
			uint8_t newTileY = (location->getY() + moveY) >> 4;
			if (moveX == 1) newTileX += 1;
			if (moveY == 1) newTileY += 1;

			if (location->getMap().isPassable(newTileX, newTileY))
			{
				if (moveX != 0) location->updateX(moveX);
				if (moveY != 0) location->updateY(moveY);
			}
		}
		else
		{
			if (moveX != 0) location->updateX(moveX);
			if (moveY != 0) location->updateY(moveY);
		}
	}
	else
	{
		player->isMoving = false;
	}
}

void Game::display()
{
	// first we clear our screen to black
	arduboy.clear();

	drawMap();
	drawMenu();

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
			displayStartX = map.getWidth() - MAP_CANVAS_WIDTH;
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
			displayStartY = map.getHeight() - MAP_CANVAS_HEIGHT;
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

			Sprites::drawSelfMasked(MAP_CANVAS_X + x, MAP_CANVAS_Y + y, tileset, tile);
		}
	}
}

void Game::drawMenu()
{
	for (uint16_t x = 0; x != MAP_CANVAS_X; x++)
		arduboy.drawFastVLine(x, 0, 64, 1);

	drawMenuItem(0, 1, 'A', 0);
	drawMenuItem(0, 18, 'B', 1);
}

void Game::drawMenuItem(uint8_t x, uint8_t y, char button, uint8_t item)
{
	arduboy.drawChar(x + 1, y + 4, button, 0, 1, 1);
	Sprites::drawPlusMask(x + 7, y, items_plus_mask, item);
}
