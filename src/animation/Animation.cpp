#include "Animation.hpp"
#include "../globals.h"

Animation::Animation(uint8_t nbFrames, uint8_t framesPerAnimation)
	: endFrame(frameCounter + nbFrames)
	, nbFrames(nbFrames)
	, framesPerAnimation(framesPerAnimation)
{}

uint8_t Animation::getAnimationCounter() const
{
	uint8_t frameCountdown = (frameCounter > endFrame ? endFrame + 256 : endFrame) - frameCounter;
	return (nbFrames - frameCountdown) / framesPerAnimation;
}

bool Animation::isFinish() const
{
	return endFrame == frameCounter;
}
