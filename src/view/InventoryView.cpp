#include "InventoryView.hpp"

#include <Arduboy2.h>
#include "../data/bitmaps.h"
#include "globals.h"

void InventoryView::handleInput()
{
	if (arduboy.justPressed(LEFT_BUTTON) && (cursor % 4) != 0)
		cursor--;
	if (arduboy.justPressed(RIGHT_BUTTON) && cursor != (INVENTORY_SIZE - 1) && (cursor % 4) != 3)
		cursor++;
	if (arduboy.justPressed(UP_BUTTON) && cursor >= 4)
		cursor -= 4;
	if (arduboy.justPressed(DOWN_BUTTON) && cursor <= INVENTORY_SIZE - 5)
		cursor += 4;

	if (arduboy.justPressed(A_BUTTON))
		game->getPlayer()->getInventory()->switchItemA(cursor);
	if (arduboy.justPressed(B_BUTTON))
		game->getPlayer()->getInventory()->switchItemB(cursor);
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
		uint8_t x = INVENTORY_VIEW_X + 2 + (i % 4) * 25;
		uint8_t y = INVENTORY_VIEW_Y + 1 + (i / 4) * 17;

		drawItemStack(x, y, inventory->getItem(i), cursor == i);
	}
}

void InventoryView::drawItemStack(uint8_t x, uint8_t y, ItemStack *itemStack, bool selected)
{
	// Item
	uint8_t frame = static_cast<uint8_t>(itemStack->getType());
	Sprites::drawPlusMask(x + 3, y, items_plus_mask, frame);

	// Amount
	switch (itemStack->getType())
	{
		case ItemType::BOMB:
			char firstChar = (itemStack->getAmount() / 10) + '0';
			char secondChar = (itemStack->getAmount() % 10) + '0';

			arduboy.drawChar(x + 12, y, firstChar, 0, 1, 1);
			arduboy.drawChar(x + 18, y, secondChar, 0, 1, 1);
			break;
	}

	if (selected)
	{
		// Left bracket
		arduboy.drawFastVLine(x, y, 16, 0);
		arduboy.drawPixel(x + 1, y, 0);
		arduboy.drawPixel(x + 1, y + 15, 0);
		// Right bracket
		arduboy.drawFastVLine(x + 25, y, 16, 0);
		arduboy.drawPixel(x + 24, y, 0);
		arduboy.drawPixel(x + 24, y + 15, 0);
	}
}
