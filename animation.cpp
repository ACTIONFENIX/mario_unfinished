#include "animation.h"

void Animation::setFrame(unsigned frame)
{
	frameNumber = frame - 1;
}

unsigned Animation::getFrame() const
{
	return frameNumber;
}

void Animation::reset()
{
	frameNumber = 0.f;
}

void Animation::setFrameCount(unsigned count)
{
	frameCount = count;
}

void Animation::setFrameRect(IntRect rect)
{
	firstFrame = rect;
	sprite->setTextureRect(firstFrame);
}

void Animation::setDistance(unsigned framesDistance)
{
	distance = framesDistance;
}

void Animation::setFrameSpeed(float speed)
{
	frameSpeed = speed;
}

void Animation::draw(RenderTarget& target, RenderStates states) const
{
	target.draw(*sprite, states);
	IntRect newFrame = firstFrame;
	if (frameNumber + frameSpeed < frameCount)
	{
		frameNumber += frameSpeed;
	}
	else
	{
		frameNumber = 0.f;
	}
	newFrame.left += int(frameNumber) * distance; 
	sprite->setTextureRect(newFrame);
}
