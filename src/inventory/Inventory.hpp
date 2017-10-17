#ifndef INVENTORY_HPP
#define INVENTORY_HPP

#include "ItemStack.hpp"

#define INVENTORY_SIZE 10

class Inventory
{
	ItemStack * items[INVENTORY_SIZE];
	ItemStack * itemA;
	ItemStack * itemB;

public:
	Inventory();
	bool addItem(ItemStack *);
	bool removeItem(ItemType itemType, uint8_t = 1);
	ItemStack * getItem(uint8_t) const;

	ItemStack * getItemA() const;
	ItemStack * getItemB() const;
	void switchItemA(uint8_t index);
	void switchItemB(uint8_t index);
};

#endif
