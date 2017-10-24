#ifndef PLAYER_SWINGS_SWORD_ANIMATION_HPP
#define PLAYER_SWINGS_SWORD_ANIMATION_HPP

#include "../Animation.hpp"

#define PLAYER_SWINGS_SWORD_DURATION 2

class PlayerSwingsSwordAnimation : public Animation
{
public:
	PlayerSwingsSwordAnimation();
	void onAnimationEnd();
	void display(Player *player, uint8_t displayPlayerX, uint8_t displayPlayerY);
};

#endif
