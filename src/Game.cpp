#include "Game.hpp"

#include "generated/mapData.h"

Game::Game()
	: entities(20)
	, toRemove(10)
{
	// TODO: load game state from EEPROM
	Location * location = new Location(SPAWN_MAP, SPAWN_X << 4,  SPAWN_Y << 4);
	player = new Player(location);
}

Player * Game::getPlayer() const
{
	return player;
}

void Game::lockMapInput()
{
	mapInputLocked = true;
}

void Game::unlockMapInput()
{
	mapInputLocked = false;
}


bool Game::isMapInputLocked() const
{
	return mapInputLocked;
}

void Game::update()
{
	// Remove entities that should be removed
	if (!toRemove.isEmpty() && !entities.isEmpty())
	{
		for (uint8_t i = 0; i != toRemove.getSize(); i++)
		{
			entities.remove(toRemove.get(i));
		}
		toRemove.clear();
	}

	viewSelector->handleInput();
	viewSelector->draw();
}

void Game::addEntity(Entity *entity)
{
	entities.add(entity);
}

DArray<Entity *> * Game::getEntities()
{
	return &entities;
}

void Game::removeEntity(Entity *entity)
{
	toRemove.add(entity);
}
