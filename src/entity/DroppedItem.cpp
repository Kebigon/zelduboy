#include "DroppedItem.hpp"

DroppedItem::DroppedItem(ItemStack *item, Location *location)
	: Entity(location)
	, item(item)
{}

ItemType DroppedItem::getType() const
{
	return item->getType();
}

ItemStack * DroppedItem::getItemStack() const
{
	return item;
}

void DroppedItem::update()
{
	physicsComponent->update(this);
}

void DroppedItem::draw()
{
	graphicsComponent->draw(this);
}
