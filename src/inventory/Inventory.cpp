#include "Inventory.hpp"

bool Inventory::addItem(ItemStack & newItem)
{
	if (newItem.getType() == ItemType::NONE)
		return true;

	for (uint8_t i = 0; i != INVENTORY_SIZE; i++)
		if (items[i].getType() == ItemType::NONE)
			items[i] = newItem;

	return false;
}

bool Inventory::removeItem(ItemType itemType, uint8_t amount)
{
	// TODO
	return false;
}

ItemStack * Inventory::getItem(uint8_t index) const
{
	return &items[index];
}
