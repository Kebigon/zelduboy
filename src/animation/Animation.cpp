#include "Animation.hpp"
#include "../globals.h"

Animation::Animation(uint8_t duration)
	: endFrame(frameCounter + duration)
{}

uint8_t Animation::getAnimationCountdown() const
{
	return (frameCounter > endFrame ? endFrame + 256 : endFrame) - frameCounter;
}

bool Animation::isFinish() const
{
	return endFrame == frameCounter;
}
