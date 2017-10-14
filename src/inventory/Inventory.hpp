#ifndef INVENTORY_HPP
#define INVENTORY_HPP

#include "ItemStack.hpp"

#define ITEM_A 0
#define ITEM_B 1
#define INVENTORY_SIZE 10

class Inventory
{
	ItemStack items[INVENTORY_SIZE];

public:
	bool addItem(ItemStack &);
	bool removeItem(ItemType itemType, uint8_t = 1);
	ItemStack * getItem(uint8_t) const;
};

#endif
