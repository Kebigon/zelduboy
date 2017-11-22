#ifndef ANIMATION_HPP
#define ANIMATION_HPP

#include <stdint.h>

class Player;

class Animation
{
public:
	virtual bool isFinish() const = 0;
	virtual void onAnimationEnd() = 0;
	virtual void display(Player *player, uint8_t displayPlayerX, uint8_t displayPlayerY) = 0;
};

#endif
