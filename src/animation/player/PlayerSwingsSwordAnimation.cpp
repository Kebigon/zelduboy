#include "PlayerSwingsSwordAnimation.hpp"

#include "../../globals.h"
#include "../../data/bitmaps.h"

PlayerSwingsSwordAnimation::PlayerSwingsSwordAnimation()
	: Animation(PLAYER_SWINGS_SWORD_NB_FRAMES, PLAYER_SWINGS_SWORD_FRAMES_PER_ANIM)
{
	game->lockMapInput();
}

void PlayerSwingsSwordAnimation::onAnimationEnd()
{
	game->unlockMapInput();
}

#define PLAYER_SWORD_DOWN_0  0
#define PLAYER_SWORD_DOWN_1  1
#define PLAYER_SWORD_LEFT_0  2
#define PLAYER_SWORD_LEFT_1  3
#define PLAYER_SWORD_UP_0    4
#define PLAYER_SWORD_UP_1    5
#define PLAYER_SWORD_RIGHT_0 6
#define PLAYER_SWORD_RIGHT_1 7

#define ANIM_SWORD_DOWN_LEFT 0
#define ANIM_SWORD_DOWN      1
#define ANIM_SWORD_UP_LEFT   2
#define ANIM_SWORD_LEFT      3
#define ANIM_SWORD_UP_RIGHT   4
#define ANIM_SWORD_UP      5

void PlayerSwingsSwordAnimation::display(Player *player, uint8_t displayPlayerX, uint8_t displayPlayerY)
{
	uint8_t frame;

	switch (player->direction)
	{
		case Direction::DOWN:
			switch (getAnimationCounter())
			{
				case 0:
					drawPlayerAndSword(displayPlayerX, displayPlayerY, PLAYER_SWORD_DOWN_0, -16,  0, ANIM_SWORD_LEFT     );
					break;
				case 1:
					drawPlayerAndSword(displayPlayerX, displayPlayerY, PLAYER_SWORD_DOWN_1, -16, 16, ANIM_SWORD_DOWN_LEFT);
					break;
				case 2:
					drawPlayerAndSword(displayPlayerX, displayPlayerY, PLAYER_SWORD_DOWN_1,   0, 16, ANIM_SWORD_DOWN     );
					break;
			}
			break;
		case Direction::LEFT:
			// frame = animCountdown == 1 ? 2 : 3;
			break;
		case Direction::UP:
			// frame = animCountdown == 1 ? 4 : 5;
			break;
		case Direction::RIGHT:
			// frame = animCountdown == 1 ? 6 : 7;
			break;
		default:
			return;
	}
}

void PlayerSwingsSwordAnimation::drawPlayerAndSword(uint8_t x, uint8_t y, uint8_t pFrame, int8_t sX, int8_t sY, uint8_t sFrame) const
{
	Sprites::drawPlusMask(x, y, playerSword_plus_mask,  pFrame);
	Sprites::drawPlusMask(x + sX, y + sY, animationSword_plus_mask, sFrame);
}
