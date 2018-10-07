#ifndef ANIMATION_SPRITE_HOLDER_H
#define ANIMATION_SPRITE_HOLDER_H
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/System/NonCopyable.hpp>
#include <memory>

using namespace sf;
using namespace std;

class AnimationSpriteHolder: public NonCopyable
{	
public:
	AnimationSpriteHolder() = default;
	~AnimationSpriteHolder() = default;
	
public:
	friend class AnimationHolder;
	
public:
	Sprite& operator*()
	{
		return *spritePtr;
	}
	const Sprite& operator*() const
	{
		return *spritePtr;
	}
	Sprite* operator->()
	{
		return spritePtr.get();
	}
	const Sprite* operator->() const
	{
		return spritePtr.get();
	}
	
private:
	mutable shared_ptr<Sprite> spritePtr{new Sprite};
};

#endif //ANIMATION_SPRITE_HOLDER_H