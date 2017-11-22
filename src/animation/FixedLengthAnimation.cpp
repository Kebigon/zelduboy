#include "FixedLengthAnimation.hpp"
#include "../globals.h"

FixedLengthAnimation::FixedLengthAnimation(uint8_t nbFrames, uint8_t framesPerAnimation)
	: endFrame(frameCounter + nbFrames)
	, nbFrames(nbFrames)
	, framesPerAnimation(framesPerAnimation)
{}

uint8_t FixedLengthAnimation::getAnimationCounter() const
{
	uint8_t frameCountdown = (frameCounter > endFrame ? endFrame + 256 : endFrame) - frameCounter;
	return (nbFrames - frameCountdown) / framesPerAnimation;
}

bool FixedLengthAnimation::isFinish() const
{
	return endFrame == frameCounter;
}
