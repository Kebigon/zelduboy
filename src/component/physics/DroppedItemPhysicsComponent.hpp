#ifndef DROPPED_ITEM_PHYSICS_COMPONENT_HPP
#define DROPPED_ITEM_PHYSICS_COMPONENT_HPP

#include "PhysicsComponent.hpp"

class DroppedItem;

class DroppedItemPhysicsComponent : public PhysicsComponent
{
public:
	void update(DroppedItem *item);
};

#endif
