#ifndef GAME_HPP
#define GAME_HPP

#include "Player.hpp"

class Game
{
public:
	void handleInput();
	void display();
	void draw(const uint8_t[], uint8_t, Player &);

	static int16_t pixelToTileCoord(int16_t);
private:
	Player player;
};

#endif
