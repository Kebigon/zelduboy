#include "Game.hpp"


#include "data/chunksdata.h"

Game::Game()
	: entities()
	, toRemove()
{
	// TODO: load game state from EEPROM
	Location * location = new Location(mapHouse, 16, 16);
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
	if (!toRemove.empty() && !entities.empty())
	{
		for (std::vector<Entity *>::iterator it = toRemove.begin(); it != toRemove.end(); ++it)
		{
			std::vector<Entity *>::iterator found = std::find(entities.begin(), entities.end(), *it);
			if (found != entities.end())
				entities.erase(found);
			toRemove.erase(it);
		}
	}

	viewSelector->handleInput();
	viewSelector->draw();
}

void Game::addEntity(Entity *entity)
{
	entities.push_back(entity);
}

std::vector<Entity *> Game::getEntities()
{
	return entities;
}

void Game::removeEntity(Entity *entity)
{
	toRemove.push_back(entity);
}
