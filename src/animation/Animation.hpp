#ifndef ANIMATION_HPP
#define ANIMATION_HPP

#include <stdint.h>

class Player;

class Animation
{
	uint8_t endFrame;

public:
	Animation(uint8_t duration);
	uint8_t getAnimationCountdown() const;
	bool isFinish() const;
	virtual void onAnimationEnd() = 0;
	virtual void display(Player *player, uint8_t displayPlayerX, uint8_t displayPlayerY) = 0;
};

#endif
