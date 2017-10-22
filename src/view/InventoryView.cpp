#include "InventoryView.hpp"

#include <Arduboy2.h>
#include "../data/bitmaps.h"
#include "globals.h"

void InventoryView::handleInput()
{
	// TODO
}

void InventoryView::draw()
{
	drawInventory(game->getPlayer()->getInventory());
}

void InventoryView::drawInventory(Inventory *inventory)
{
	arduboy.drawFastVLine(INVENTORY_VIEW_X, 0, 64, 0);

	for (int x = INVENTORY_VIEW_X + 1; x != SCREEN_WIDTH; x++)
		arduboy.drawFastVLine(x, 0, 64, 1);

	for (int i = 0; i != INVENTORY_SIZE; i++)
	{
		uint8_t x = INVENTORY_VIEW_X + 2 + (i % 4) * 9;
		uint8_t y = INVENTORY_VIEW_Y + 1 + (i / 4) * 17;

		drawItemStack(x, y, inventory->getItem(i));
	}
}

void InventoryView::drawItemStack(uint8_t x, uint8_t y, ItemStack *itemStack)
{
	uint8_t frame = static_cast<uint8_t>(itemStack->getType());

	Sprites::drawPlusMask(x, y, items_plus_mask, frame);
}
