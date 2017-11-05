#include <Arduboy2.h>
#include "Game.hpp"
#include "data/chunksdata.h"
#include "entity/DroppedItem.hpp"
#include "Location.hpp"

Map *mapHouse = new Map(mapHouseData);

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
}

void loop()
{
	if (!(arduboy.nextFrame()))
		return;

	frameCounter++;

	game->update();
}
