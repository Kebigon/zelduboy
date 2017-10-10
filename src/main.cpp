#include <Arduboy2.h>
#include "Game.hpp"
#include "chunksdata.h"

Map mapHouse(mapHouseData);

Arduboy2 arduboy;
Game game;

void setup()
{
	arduboy.begin();
	arduboy.setFrameRate(30);

	Serial.begin(9600);
}

void loop()
{
	if (!(arduboy.nextFrame()))
		return;

	game.handleInput();
	game.display();
}
