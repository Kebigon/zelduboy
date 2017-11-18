#ifndef ANIMATION_HPP
#define ANIMATION_HPP

#include <stdint.h>

class Player;

class Animation
{
private:
	uint8_t endFrame;
	uint8_t nbFrames;
	uint8_t framesPerAnimation;

public:
	Animation(uint8_t duration, uint8_t framesPerAnimation);
	uint8_t getAnimationCounter() const;
	bool isFinish() const;
	virtual void onAnimationEnd() = 0;
	virtual void display(Player *player, uint8_t displayPlayerX, uint8_t displayPlayerY) = 0;
};

#endif
