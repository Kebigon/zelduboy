#ifndef GAME_HPP
#define GAME_HPP

#include "utils/DArray.hpp"
#include "entity/Player.hpp"
#include "view/ViewSelector.hpp"

class Game
{
	Player * player;
	ViewSelector *viewSelector = new ViewSelector();
	bool mapInputLocked = false;
	// std::vector<Entity *> entities;
	// std::vector<Entity *> toRemove;
	DArray<Entity *> entities;
	DArray<Entity *> toRemove;

public:
	Game();
	Player * getPlayer() const;
	void update();
	void lockMapInput();
	void unlockMapInput();
	bool isMapInputLocked() const;
	void addEntity(Entity *entity);
	DArray<Entity *> getEntities();
	void removeEntity(Entity *entity);
};

#endif
