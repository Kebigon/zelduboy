#include <Arduboy2.h>
#include <Sprites.h>

#include "bitmaps.h"
#include "Player.hpp"

Player::Player()
	:isMoving(false), x(16), y(16)
{}

void Player::draw()
{
	uint8_t frame = direction << 1;

	if (isMoving)
	{
		switch (direction)
		{
		case LEFT:
		case RIGHT:
			frame += (x >> 2) % 2;
			break;
		case UP:
		case DOWN:
			frame += (y >> 2) % 2;
			break;
		}
	}

	//Sprites::drawPlusMask(x, y, link_plus_mask, frame);
	Sprites::drawPlusMask((128-16) / 2, (64-16) / 2, link_plus_mask, frame);
}
