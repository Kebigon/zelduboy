#include "PlayerSwingsSwordAnimation.hpp"

#include "../../globals.h"

PlayerSwingsSwordAnimation::PlayerSwingsSwordAnimation(uint8_t endCounter)
	: Animation(endCounter)
{}

void PlayerSwingsSwordAnimation::onAnimationEnd()
{
	game->unlockMapInput();
}

void PlayerSwingsSwordAnimation::display(Player *player, uint8_t displayPlayerX, uint8_t displayPlayerY)
{
	switch (player->direction)
	{
		case Direction::LEFT:

			break;
	}
}
