#ifndef INVENTORY_VIEW_HPP
#define INVENTORY_VIEW_HPP

#include "View.hpp"

#define INVENTORY_VIEW_X 16
#define INVENTORY_VIEW_Y  0

class InventoryView : public View
{
	void drawInventory(Inventory *inventory);
	void drawItemStack(uint8_t x, uint8_t y, ItemStack *itemStack);

public:
	virtual void handleInput();
	virtual void draw();
};

#endif
