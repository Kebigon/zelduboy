#include "DroppedItemPhysicsComponent.hpp"

#include <Arduboy2.h>

#include "entity/DroppedItem.hpp"
#include "globals.h"

void DroppedItemPhysicsComponent::update(DroppedItem *item)
{
	Rect itemRect = { item->getLocation()->getX(), item->getLocation()->getY(), items_plus_mask[0], items_plus_mask[1] };
	Rect playerRect = { item->getLocation()->getX(), item->getLocation()->getY(), link_plus_mask[0], link_plus_mask[1] };

	if (arduboy.collide(itemRect, playerRect))
	{
		// game->getPlayer()->getInventory()->addItem(item->getItemStack());
		game->removeEntity(item);
	}
}
