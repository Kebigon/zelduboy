#ifndef DROPPED_ITEM_HPP
#define DROPPED_ITEM_HPP

#include "Entity.hpp"
#include "inventory/ItemStack.hpp"
#include "component/graphics/DroppedItemGraphicsComponent.hpp"
#include "component/physics/DroppedItemPhysicsComponent.hpp"

class DroppedItem : public Entity
{
	DroppedItemGraphicsComponent *graphicsComponent = new DroppedItemGraphicsComponent();
	DroppedItemPhysicsComponent * physicsComponent = new DroppedItemPhysicsComponent();
	ItemStack *item;
public:
	DroppedItem(ItemStack *item, Location *location);
	ItemType getType() const;
	ItemStack * getItemStack() const;
	void update();
	void draw();
};

#endif
