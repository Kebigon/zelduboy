#include "PhysicsComponent.hpp"

#include "globals.h"
#include "entity/MovableBlock.hpp"

bool PhysicsComponent::checkMapPassability(Location *location, int8_t velocityX, int8_t velocityY)
{
	bool checkPassableX = location->getX() % TILE_SIZE == 0;
	bool checkPassableY = location->getY() % TILE_SIZE == 0;

	// We stay on the same tile: nothing to check
	if (!checkPassableX && !checkPassableY)
		return true;

	// TODO: probably something to clarify here
	uint8_t newTileX = (location->getX() + velocityX) >> 4;
	uint8_t newTileY = (location->getY() + velocityY) >> 4;
	if (velocityX == 1) newTileX += 1;
	if (velocityY == 1) newTileY += 1;

	if (location->getMap()->isPassable(newTileX, newTileY))
		return true;

	return false;
}

bool PhysicsComponent::checkEntityCollisions(Rect playerCollisionBox, int8_t velocityX, int8_t velocityY)
{
	playerCollisionBox.x +=velocityX;
	playerCollisionBox.y +=velocityY;

	DArray<Entity *> *entities = game->getEntities();
	for (int i = 0; i != entities->getSize(); i++)
	{
		Entity *entity = entities->get(i);

		if (entity != NULL && !entity->isPassable() && entity->collideWith(playerCollisionBox))
		{
			switch (entity->getType())
			{
				case EntityType::MOVABLE_BLOCK:
					return ((MovableBlock *)entity)->push(velocityX, velocityY);
				default:
					return false;
			}
		}
	}

	return true;
}
