#ifndef ANIMATION_HPP
#define ANIMATION_HPP

#include <stdint.h>

class Animation
{
	uint8_t endFrame;

public:
	Animation(uint8_t endCounter);
	bool isFinish() const;
	virtual void onAnimationEnd() = 0;
	virtual void display() = 0;
};

#endif
