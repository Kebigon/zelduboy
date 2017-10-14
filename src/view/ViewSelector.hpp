#ifndef VIEW_SELECTOR_HPP
#define VIEW_SELECTOR_HPP

#include "InventoryView.hpp"
#include "MapView.hpp"

class ViewSelector : public View
{
	View *currentView;
	InventoryView *inventoryView;
	MapView *mapView;

	void drawMenu();
	void drawMenuItem(uint8_t, uint8_t, char, ItemStack *);

public:
	ViewSelector(Game *game);
	virtual void handleInput();
	virtual void draw();
};

#endif
