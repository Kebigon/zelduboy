#ifndef GAME_HPP
#define GAME_HPP

#include "Player.hpp"
#include "Map.hpp"

class Game
{
public:
	Game();
	void handleInput();
	void display();
	void drawMap();

	static int16_t pixelToTileCoord(int16_t);
private:
	Player * player;
};

#endif
