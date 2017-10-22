#include "MapView.hpp"

#include "globals.h"
#include "../data/chunksdata.h"
#include "../data/bitmaps.h"


void MapView::handleInput()
{
	if (game->isMapInputLocked())
		return;

	Player *player = game->getPlayer();
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

			if (location->getMap()->isPassable(newTileX, newTileY))
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

void MapView::draw()
{
	Player *player = game->getPlayer();

	drawMap(player);
	drawPlayer(player);
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

void MapView::drawPlayer(Player *player)
{
	Location *location = player->getLocation();

	uint16_t playerX = location->getX();
	uint16_t playerY = location->getY();
	Map *map = location->getMap();

	uint8_t displayPlayerX, displayPlayerY;

	switch (player->getHorizontalPosition())
	{
		case PlayerHorizontalPosition::LEFT:
			displayPlayerX = playerX;
			break;
		case PlayerHorizontalPosition::CENTER:
			displayPlayerX = PLAYER_CENTER_POS_LEFT;
			break;
		case PlayerHorizontalPosition::RIGHT:
			displayPlayerX = playerX - (map->getWidth() - MAP_CANVAS_WIDTH);
			break;
	}

	switch (player->getVerticalPosition())
	{
		case PlayerVerticalPosition::TOP:
			displayPlayerY = playerY;
			break;
		case PlayerVerticalPosition::CENTER:
			displayPlayerY = PLAYER_CENTER_POS_TOP;
			break;
		case PlayerVerticalPosition::BOTTOM:
			displayPlayerY = playerY - (map->getHeight() - MAP_CANVAS_HEIGHT);
			break;
	}

	uint8_t frame = static_cast<int>(player->direction) << 1;

	if (player->isMoving)
	{
		switch (player->direction)
		{
			case Direction::LEFT:
			case Direction::RIGHT:
				frame += (playerX >> 2) % 2;
				break;
			case Direction::UP:
			case Direction::DOWN:
				frame += (playerY >> 2) % 2;
				break;
		}
	}

	Sprites::drawPlusMask(MAP_CANVAS_X + displayPlayerX, MAP_CANVAS_Y + displayPlayerY, link_plus_mask, frame);
}
