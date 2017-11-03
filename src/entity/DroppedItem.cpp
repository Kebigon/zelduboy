#include "DroppedItem.hpp"

DroppedItem::DroppedItem(ItemStack *item, Location *location)
	: Entity(location)
	, item(item)
{}

ItemType DroppedItem::getType() const
{
	return item->getType();
}

void DroppedItem::update()
{
}

void DroppedItem::draw()
{
	graphicsComponent->draw(this);
}
