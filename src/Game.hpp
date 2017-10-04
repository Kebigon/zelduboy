#ifndef GAME_HPP
#define GAME_HPP

#include "Player.hpp"
#include "Map.hpp"

class Game
{
public:
	void handleInput();
	void display();
	void draw(Map &, Player &);

	static int16_t pixelToTileCoord(int16_t);
private:
	Player player;
};

#endif
