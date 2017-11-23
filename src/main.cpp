#include <Arduboy2.h>
#include "Game.hpp"
#include "data/chunksdata.h"
#include "entity/DroppedItem.hpp"
#include "entity/MovableBlock.hpp"
#include "Location.hpp"

Room *room1 = new Room(0,0,room1Data);
Map *mapHouse = new Map({room1}, 1);

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

	DroppedItem *item = new DroppedItem(new ItemStack(ItemType::SWORD), new Location(mapHouse, 48, 48));
	game->addEntity(item);
	MovableBlock *block = new MovableBlock(new Location(mapHouse, 64, 48));
	game->addEntity(block);
}

void loop()
{
	if (!(arduboy.nextFrame()))
		return;

	frameCounter++;

	game->update();
}
