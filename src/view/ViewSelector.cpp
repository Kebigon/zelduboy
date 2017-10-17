#include "ViewSelector.hpp"

#include "globals.h"
#include "../data/bitmaps.h"

ViewSelector::ViewSelector(Game *game)
	: View(game)
	, inventoryView(new InventoryView(game))
	, mapView(new MapView(game))
	, currentView(mapView)
{}

void ViewSelector::handleInput()
{
	arduboy.pollButtons();

	if ((arduboy.justPressed(LEFT_BUTTON) && arduboy.pressed(RIGHT_BUTTON))
			|| (arduboy.pressed(LEFT_BUTTON) && arduboy.justPressed(RIGHT_BUTTON)))
	{
		currentView = currentView == mapView ? (View*)inventoryView : (View*)mapView;
		return;
	}

	currentView->handleInput();
}

void ViewSelector::draw()
{
	// first we clear our screen to black
	arduboy.clear();

	currentView->draw();
	drawMenu();

	arduboy.display();
}

void ViewSelector::drawMenu()
{
	for (uint16_t x = 0; x != MAP_CANVAS_X; x++)
		arduboy.drawFastVLine(x, 0, 64, 1);

	Inventory *inventory = game->getPlayer()->getInventory();

	drawMenuItem(0, 1, 'A', inventory->getItemA());
	drawMenuItem(0, 18, 'B', inventory->getItemB());
}

void ViewSelector::drawMenuItem(uint8_t x, uint8_t y, char button, ItemStack * item)
{
	uint8_t itemFrame = static_cast<uint8_t>(item->getType());

	arduboy.drawChar(x + 1, y + 4, button, 0, 1, 1);
	Sprites::drawPlusMask(x + 7, y, items_plus_mask, itemFrame);
}
