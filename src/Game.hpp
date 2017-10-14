#ifndef GAME_HPP
#define GAME_HPP

#include "Player.hpp"

class Game
{
	Player * player;

public:
	Game();
	Player * getPlayer() const;
};

#endif
