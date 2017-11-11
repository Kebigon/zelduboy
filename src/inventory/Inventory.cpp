#include "Inventory.hpp"

Inventory::Inventory()
{
	itemA = new ItemStack();
	itemB = new ItemStack();

	for (int i = 0; i != INVENTORY_SIZE; i++)
		items[i] = new ItemStack();
}

bool Inventory::addItem(ItemStack * newItem)
{
	if (newItem->getType() == ItemType::NONE)
		return true;

	if (itemA->getType() == ItemType::NONE)
	{
		delete itemA;
		itemA = newItem;
		return true;
	}

	if (itemB->getType() == ItemType::NONE)
	{
		delete itemB;
		itemB = newItem;
		return true;
	}

	for (uint8_t i = 0; i != INVENTORY_SIZE; i++)
		if (items[i]->getType() == ItemType::NONE)
		{
			delete items[i];
			items[i] = newItem;
			return true;
		}

	return false;
}

bool Inventory::removeItem(ItemType itemType, uint8_t amount)
{
	// TODO
	return false;
}

ItemStack * Inventory::getItem(uint8_t index) const
{
	return items[index];
}

ItemStack * Inventory::getItemA() const
{
	return itemA;
}

ItemStack * Inventory::getItemB() const
{
	return itemB;
}

void Inventory::switchItemA(uint8_t index)
{
	ItemStack * tmp = itemA;
	itemA = items[index];
	items[index] = tmp;
}

void Inventory::switchItemB(uint8_t index)
{
	ItemStack * tmp = itemB;
	itemB = items[index];
	items[index] = tmp;
}
