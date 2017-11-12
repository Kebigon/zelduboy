#include "PlayerSwingsSwordAnimation.hpp"

#include "../../globals.h"
#include "../../data/bitmaps.h"

PlayerSwingsSwordAnimation::PlayerSwingsSwordAnimation()
	: Animation(PLAYER_SWINGS_SWORD_DURATION)
{
	game->lockMapInput();
}

void PlayerSwingsSwordAnimation::onAnimationEnd()
{
	game->unlockMapInput();
}

void PlayerSwingsSwordAnimation::display(Player *player, uint8_t displayPlayerX, uint8_t displayPlayerY)
{
	uint8_t frame;

	switch (player->direction)
	{
		case Direction::DOWN:
			frame = (getAnimationCountdown() >> 3) == 1 ? 0 : 1;
			break;
		case Direction::LEFT:
			frame = (getAnimationCountdown() >> 3) == 1 ? 2 : 3;
			break;
		case Direction::UP:
			frame = (getAnimationCountdown() >> 3) == 1 ? 4 : 5;
			break;
		case Direction::RIGHT:
			frame = (getAnimationCountdown() >> 3) == 1 ? 6 : 7;
			break;
		default:
			return;
	}

	Sprites::drawPlusMask(displayPlayerX, displayPlayerY, playerSword_plus_mask,  frame);
}
