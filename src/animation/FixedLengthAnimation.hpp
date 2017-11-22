#ifndef FIXED_LENGTH_ANIMATION_HPP
#define FIXED_LENGTH_ANIMATION_HPP

#include <stdint.h>
#include "Animation.hpp"

class FixedLengthAnimation : public Animation
{
private:
	uint8_t endFrame;
	uint8_t nbFrames;
	uint8_t framesPerAnimation;

public:
	FixedLengthAnimation(uint8_t duration, uint8_t framesPerAnimation);
	uint8_t getAnimationCounter() const;
	bool isFinish() const;
};

#endif
