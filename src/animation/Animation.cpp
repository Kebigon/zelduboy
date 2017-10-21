#include "Animation.hpp"
#include "../globals.h"

Animation::Animation(uint8_t endFrame)
	: endFrame(endFrame)
{}

bool Animation::isFinish() const
{
	return endFrame == frameCounter;
}
