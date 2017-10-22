#include <Arduboy2.h>
#include "Game.hpp"
#include "view/ViewSelector.hpp"
#include "data/chunksdata.h"

Map *mapHouse = new Map(mapHouseData);

uint8_t frameCounter = 0;
Arduboy2 arduboy;
Game *game;
ViewSelector *viewSelector;

void setup()
{
	// Initializa the serial port for debug purpose
	Serial.begin(9600);

	// Initializa Arduboy2 library
	arduboy.begin();
	arduboy.setFrameRate(30);

	game = new Game();
	viewSelector = new ViewSelector();
}

void loop()
{
	if (!(arduboy.nextFrame()))
		return;

	frameCounter++;

	viewSelector->handleInput();
	viewSelector->draw();
}
