#include "PhysicsComponent.hpp"

#include "globals.h"

void PhysicsComponent::update(Player *player)
{
	int8_t velocityX = player->getVelocityX();
	int8_t velocityY = player->getVelocityY();

	if (velocityX != 0 || velocityY != 0)
	{
		player->isMoving = true;

		Location *location = player->getLocation();
		bool checkPassableX = location->getX() % TILE_SIZE == 0;
		bool checkPassableY = location->getY() % TILE_SIZE == 0;

		if (checkPassableX || checkPassableY)
		{
			uint8_t newTileX = (location->getX() + velocityX) >> 4;
			uint8_t newTileY = (location->getY() + velocityY) >> 4;
			if (velocityX == 1) newTileX += 1;
			if (velocityY == 1) newTileY += 1;

			if (location->getMap()->isPassable(newTileX, newTileY))
			{
				if (velocityX != 0) location->updateX(velocityX);
				if (velocityY != 0) location->updateY(velocityY);
			}
		}
		else
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
