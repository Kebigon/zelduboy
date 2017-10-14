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
	void drawMenu();
	void drawMenuItem(uint8_t, uint8_t, char, uint8_t);

	static int16_t pixelToTileCoord(int16_t);
private:
	Player * player;
};

#endif
