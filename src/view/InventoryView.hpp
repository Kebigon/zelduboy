#ifndef INVENTORY_VIEW_HPP
#define INVENTORY_VIEW_HPP

#include "View.hpp"

class InventoryView : public View
{
	void drawInventory(Inventory *inventory);

public:
	InventoryView(Game *game);
	virtual void handleInput();
	virtual void draw();
};

#endif
