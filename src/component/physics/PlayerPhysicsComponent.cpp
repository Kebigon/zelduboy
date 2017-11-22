#include "PlayerPhysicsComponent.hpp"

#include "entity/Player.hpp"

void PlayerPhysicsComponent::update(Player *player)
{
	int8_t velocityX = player->getVelocityX();
	int8_t velocityY = player->getVelocityY();

	if (velocityX != 0 || velocityY != 0)
	{
		player->isMoving = true;

		Location *location = player->getLocation();

		if (checkMapPassability(location, velocityX, velocityY) && checkEntityCollisions(player->getCollisionBox(), velocityX, velocityY))
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
