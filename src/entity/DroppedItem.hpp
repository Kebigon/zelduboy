#ifndef DROPPED_ITEM_HPP
#define DROPPED_ITEM_HPP

#include "Entity.hpp"
#include "../inventory/ItemStack.hpp"
#include "../component/DroppedItemGraphicsComponent.hpp"

class DroppedItem : public Entity
{
	DroppedItemGraphicsComponent *graphicsComponent = new DroppedItemGraphicsComponent();
	ItemStack *item;
public:
	DroppedItem(ItemStack *item, Location *location);
	ItemType getType() const;
	void update();
	void draw();
};

#endif
