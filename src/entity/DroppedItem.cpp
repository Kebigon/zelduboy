#include "DroppedItem.hpp"

DroppedItem::DroppedItem(ItemStack *item, Location *location)
	: Entity(location)
	, item(item)
{}

EntityType DroppedItem::getType() const
{
	return EntityType::DROPPED_ITEM;
}

ItemType DroppedItem::getItemType() const
{
	return item->getType();
}

ItemStack * DroppedItem::getItemStack() const
{
	return item;
}

void DroppedItem::update()
{
	physicsComponent.update(this);
}

void DroppedItem::draw()
{
	graphicsComponent.draw(this);
}
