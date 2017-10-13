#include "Player.hpp"

#include <Arduboy2.h>
#include <Sprites.h>
#include "bitmaps.h"
#include "globals.h"

Player::Player(Location * location)
	: location(location)
	, isMoving(false)
	, direction(Direction::DOWN)
{}

Location * Player::getLocation() const
{
	return location;
}

PlayerHorizontalPosition Player::getHorizontalPosition() const
{
	uint16_t playerX = location->getX();

	if (playerX < PLAYER_CENTER_POS_LEFT) // Close to left border of the map
		return PlayerHorizontalPosition::LEFT;
	else if (playerX > location->getMap().getWidth() - PLAYER_CENTER_POS_RIGHT) // Close to the right border of the map
		return PlayerHorizontalPosition::RIGHT;
	else
		return PlayerHorizontalPosition::CENTER;
}

PlayerVerticalPosition Player::getVerticalPosition() const
{
	uint16_t playerY = location->getY();

	if (playerY < PLAYER_CENTER_POS_TOP) // Close to top border of the map
		return PlayerVerticalPosition::TOP;
	else if (playerY > location->getMap().getHeight() - PLAYER_CENTER_POS_BOTTOM) // Close to the bottom border of the map
		return PlayerVerticalPosition::BOTTOM;
	else
		return PlayerVerticalPosition::CENTER;
}

void Player::draw()
{
	uint16_t playerX = location->getX();
	uint16_t playerY = location->getY();
	Map map = location-> getMap();
	uint8_t displayPlayerX, displayPlayerY;

	switch (getHorizontalPosition())
	{
		case PlayerHorizontalPosition::LEFT:
			displayPlayerX = playerX;
			break;
		case PlayerHorizontalPosition::CENTER:
			displayPlayerX = PLAYER_CENTER_POS_LEFT;
			break;
		case PlayerHorizontalPosition::RIGHT:
			displayPlayerX = playerX - (map.getWidth() - MAP_CANVAS_WIDTH);
			break;
	}

	switch (getVerticalPosition())
	{
		case PlayerVerticalPosition::TOP:
			displayPlayerY = playerY;
			break;
		case PlayerVerticalPosition::CENTER:
			displayPlayerY = PLAYER_CENTER_POS_TOP;
			break;
		case PlayerVerticalPosition::BOTTOM:
			displayPlayerY = playerY - (map.getHeight() - MAP_CANVAS_HEIGHT);
			break;
	}


	uint8_t frame = static_cast<int>(direction) << 1;

	if (isMoving)
	{
		switch (direction)
		{
			case Direction::LEFT:
			case Direction::RIGHT:
				frame += (location->getX() >> 2) % 2;
				break;
			case Direction::UP:
			case Direction::DOWN:
				frame += (location->getY() >> 2) % 2;
				break;
		}
	}

	//Sprites::drawPlusMask(x, y, link_plus_mask, frame);
	Sprites::drawPlusMask(MAP_CANVAS_X + displayPlayerX, MAP_CANVAS_Y + displayPlayerY, link_plus_mask, frame);
	// Sprites::drawPlusMask((128 - 16) / 2, (64 - 16) / 2, link_plus_mask, frame);
}
