#ifndef DROPPED_ITEM_HPP
#define DROPPED_ITEM_HPP

#include "Entity.hpp"
#include "inventory/ItemStack.hpp"
#include "component/graphics/DroppedItemGraphicsComponent.hpp"
#include "component/physics/DroppedItemPhysicsComponent.hpp"

class DroppedItem : public Entity
{
	static DroppedItemPhysicsComponent physicsComponent;
	static DroppedItemGraphicsComponent graphicsComponent;

	ItemStack *item;

public:
	DroppedItem(ItemStack *item, Location *location);
	ItemType getItemType() const;
	ItemStack * getItemStack() const;
	virtual void update();
	virtual void draw();
	virtual EntityType getType() const;
};

#endif
