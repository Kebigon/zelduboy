#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <stdint.h>

enum Direction
{
	DOWN,
	LEFT,
	UP,
	RIGHT
};

class Player
{
public:
	Player();
	void draw();

	bool isMoving;
	uint8_t currentChunk[];
	int16_t x;
	int16_t y;
	Direction direction;
};

#endif
