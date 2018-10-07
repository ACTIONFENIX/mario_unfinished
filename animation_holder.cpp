#include "animation_holder.h"

void AnimationHolder::unifySpritePointers()
{
	shared_ptr<Sprite> alloc_sprite(new Sprite);
	for (auto& i: animations)
	{
		if (i)
		{
			alloc_sprite->setTexture(*i->sprite->getTexture());
			i->sprite = alloc_sprite;
		}
	}
}

void AnimationHolder::setSize(size_t size)
{
	animations.resize(size);
}

void AnimationHolder::addAnimation(size_t i, Animation* anim)
{
	animations[i].reset(anim);
	unifySpritePointers();
}

void AnimationHolder::play(size_t i)
{
	current = i;
}

size_t AnimationHolder::currentAnimation() const
{
	return current;
}

void AnimationHolder::stop()
{
	animations[current]->reset();
}

Animation& AnimationHolder::operator[](size_t i)
{
	return *animations[i];
}

void AnimationHolder::draw(RenderTarget& target, RenderStates states) const
{
	target.draw(*animations[current]);
}
