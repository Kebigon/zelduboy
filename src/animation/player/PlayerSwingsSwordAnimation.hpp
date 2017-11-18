#ifndef PLAYER_SWINGS_SWORD_ANIMATION_HPP
#define PLAYER_SWINGS_SWORD_ANIMATION_HPP

#include "../Animation.hpp"

#define PLAYER_SWINGS_SWORD_NB_FRAMES 6
#define PLAYER_SWINGS_SWORD_FRAMES_PER_ANIM 2

class PlayerSwingsSwordAnimation : public Animation
{
public:
	PlayerSwingsSwordAnimation();
	void onAnimationEnd();
	void display(Player *player, uint8_t displayPlayerX, uint8_t displayPlayerY);

private:
	void drawPlayerAndSword(uint8_t x, uint8_t y, uint8_t pFrame, int8_t sX, int8_t sY, uint8_t sFrame) const;
};

#endif
