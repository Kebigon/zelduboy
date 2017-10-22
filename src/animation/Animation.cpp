#include "Animation.hpp"
#include "../globals.h"

Animation::Animation(uint8_t endFrame)
	: endFrame(endFrame)
{}

uint8_t Animation::getAnimationCountdown() const
{
	return (frameCounter > endFrame ? endFrame + 256 : endFrame) - frameCounter;
}

bool Animation::isFinish() const
{
	return endFrame == frameCounter;
}
