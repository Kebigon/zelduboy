#ifndef PLAYER_SWINGS_SWORD_ANIMATION_HPP
#define PLAYER_SWINGS_SWORD_ANIMATION_HPP

#include "../Animation.hpp"

class PlayerSwingsSwordAnimation : public Animation
{
public:
	PlayerSwingsSwordAnimation(uint8_t endCounter);
	void onAnimationEnd();
	void display(Player *player, uint8_t displayPlayerX, uint8_t displayPlayerY);
};

#endif
