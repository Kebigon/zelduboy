#include "Game.hpp"

#include "globals.h"
#include "chunksdata.h"
#include "bitmaps.h"

Game::Game()
{
	Location * loc = new Location(mapHouse, 16, 16);
	player = new Player(loc);
}

Player * Game::getPlayer() const
{
	return player;
}
