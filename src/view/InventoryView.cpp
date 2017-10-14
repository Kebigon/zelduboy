#include "InventoryView.hpp"

InventoryView::InventoryView(Game *game)
	: View(game)
{}

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
	// TODO
}
