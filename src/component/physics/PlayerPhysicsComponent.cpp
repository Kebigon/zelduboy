#include "PlayerPhysicsComponent.hpp"

#include "globals.h"

void PlayerPhysicsComponent::update(Player *player)
{
	int8_t velocityX = player->getVelocityX();
	int8_t velocityY = player->getVelocityY();

	if (velocityX != 0 || velocityY != 0)
	{
		player->isMoving = true;

		Location *location = player->getLocation();

		if (checkMapPassability(location, velocityX, velocityY))
		{
			if (velocityX != 0) location->updateX(velocityX);
			if (velocityY != 0) location->updateY(velocityY);
		}
	}
	else
	{
		player->isMoving = false;
	}
}

bool PlayerPhysicsComponent::checkMapPassability(Location *location, int8_t velocityX, int8_t velocityY)
{
	bool checkPassableX = location->getX() % TILE_SIZE == 0;
	bool checkPassableY = location->getY() % TILE_SIZE == 0;

	// We stay on the same tile: nothing to check
	if (!checkPassableX && !checkPassableY)
		return true;

// TODO: probably somethinh to clarify here
	uint8_t newTileX = (location->getX() + velocityX) >> 4;
	uint8_t newTileY = (location->getY() + velocityY) >> 4;
	if (velocityX == 1) newTileX += 1;
	if (velocityY == 1) newTileY += 1;

	if (location->getMap()->isPassable(newTileX, newTileY))
		return true;

	return false;
}
