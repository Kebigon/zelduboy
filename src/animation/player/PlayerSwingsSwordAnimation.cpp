#include "PlayerSwingsSwordAnimation.hpp"

#include "../../globals.h"
#include "../../data/bitmaps.h"

PlayerSwingsSwordAnimation::PlayerSwingsSwordAnimation()
	: Animation(PLAYER_SWINGS_SWORD_DURATION)
{}

void PlayerSwingsSwordAnimation::onAnimationEnd()
{
	game->unlockMapInput();
}

void PlayerSwingsSwordAnimation::display(Player *player, uint8_t displayPlayerX, uint8_t displayPlayerY)
{
	uint8_t frame;

	switch (player->direction)
	{
		case Direction::LEFT:
			frame = getAnimationCountdown() == 1 ? 3 : 2;
			break;
		case Direction::RIGHT:
			frame = getAnimationCountdown() == 1 ? 1 : 0;
			break;
		default:
			return;
	}

	Sprites::drawPlusMask(displayPlayerX, displayPlayerY, linkSword_plus_mask,  frame);
}
