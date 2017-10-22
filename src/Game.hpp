#ifndef GAME_HPP
#define GAME_HPP

#include "entity/Player.hpp"

class Game
{
	Player * player;
	bool mapInputLocked = false;

public:
	Game();
	Player * getPlayer() const;
	void lockMapInput();
	void unlockMapInput();
	bool isMapInputLocked() const;
};

#endif
