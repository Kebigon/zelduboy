#include "Game.hpp"

#include "data/chunksdata.h"

Game::Game()
{
	// TODO: load game state from EEPROM
	Location * location = new Location(mapHouse, 16, 16);
	player = new Player(location);
}

Player * Game::getPlayer() const
{
	return player;
}
