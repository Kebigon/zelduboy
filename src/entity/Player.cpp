#include "Player.hpp"

#include <Arduboy2.h>
#include <Sprites.h>
#include "globals.h"

Player::Player(Location * location)
	: location(location)
	, isMoving(false)
	, direction(Direction::DOWN)
{}

Inventory * Player::getInventory() const
{
	return inventory;
}

Location * Player::getLocation() const
{
	return location;
}

PlayerHorizontalPosition Player::getHorizontalPosition() const
{
	uint16_t playerX = location->getX();

	if (playerX < PLAYER_CENTER_POS_LEFT) // Close to left border of the map
		return PlayerHorizontalPosition::LEFT;
	else if (playerX > location->getMap()->getWidth() - PLAYER_CENTER_POS_RIGHT) // Close to the right border of the map
		return PlayerHorizontalPosition::RIGHT;
	else
		return PlayerHorizontalPosition::CENTER;
}

PlayerVerticalPosition Player::getVerticalPosition() const
{
	uint16_t playerY = location->getY();

	if (playerY < PLAYER_CENTER_POS_TOP) // Close to top border of the map
		return PlayerVerticalPosition::TOP;
	else if (playerY > location->getMap()->getHeight() - PLAYER_CENTER_POS_BOTTOM) // Close to the bottom border of the map
		return PlayerVerticalPosition::BOTTOM;
	else
		return PlayerVerticalPosition::CENTER;
}

Animation * Player::getCurrentAnimation() const
{
	return currentAnimation;
}

void Player::setCurrentAnimation(Animation *animation)
{
	currentAnimation = animation;
}
