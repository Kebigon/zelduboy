#ifndef GAME_HPP
#define GAME_HPP

#include <ArduinoSTL.h>
#include <vector>

#include "entity/Player.hpp"
#include "view/ViewSelector.hpp"

class Game
{
	Player * player;
	ViewSelector *viewSelector = new ViewSelector();
	bool mapInputLocked = false;
	std::vector<Entity *> entities;
	std::vector<Entity *> toRemove;

public:
	Game();
	Player * getPlayer() const;
	void update();
	void lockMapInput();
	void unlockMapInput();
	bool isMapInputLocked() const;
	void addEntity(Entity *entity);
	std::vector<Entity *> getEntities();
	void removeEntity(Entity *entity);
};

#endif
