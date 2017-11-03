#ifndef DROPPED_ITEM_GRAPHICS_COMPONENT_HPP
#define DROPPED_ITEM_GRAPHICS_COMPONENT_HPP

#include "GraphicsComponent.hpp"
#include "../data/bitmaps.h"

class DroppedItem;

class DroppedItemGraphicsComponent : public GraphicsComponent
{
public:
	void draw(DroppedItem *item);
};

#endif
