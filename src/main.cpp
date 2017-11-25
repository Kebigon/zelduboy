#include <Arduboy2.h>
#include "Game.hpp"
#include "entity/DroppedItem.hpp"
#include "entity/MovableBlock.hpp"
#include "Location.hpp"
#include "generated/mapData.h"

uint8_t frameCounter = 0;
Arduboy2 arduboy;
Game *game;

void setup()
{
	// Initializa the serial port for debug purpose
	Serial.begin(9600);

	// Initializa Arduboy2 library
	arduboy.begin();
	arduboy.setFrameRate(30);

	game = new Game();

	DroppedItem *item = new DroppedItem(new ItemStack(ItemType::SWORD), new Location(SPAWN_MAP, 48, 48));
	game->addEntity(item);
	MovableBlock *block = new MovableBlock(new Location(SPAWN_MAP, 64, 48));
	game->addEntity(block);
}

void loop()
{
	if (!(arduboy.nextFrame()))
		return;

	frameCounter++;

	game->update();
}
