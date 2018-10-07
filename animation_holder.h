#ifndef ANIMATION_HOLDER_H
#define ANIMATION_HOLDER_H
#include "animation_sprite_holder.h"
#include "animation.h"
#include <vector>
#include <cstdlib>
#include <SFML/Graphics/Sprite.hpp>

using namespace sf;
using namespace std;

class Animation;

class AnimationHolder: public Drawable, public Transformable, public NonCopyable
{
public:
	AnimationHolder() = default;
	AnimationHolder(size_t size): animations(size) {}
	virtual ~AnimationHolder() = default;
	
	void setTexture (const Texture &texture, bool resetRect = false) { animations[0]->setTexture(texture, resetRect); }
	void setTextureRect (const IntRect &rectangle) { animations[0]->setTextureRect(rectangle); }
	void setColor (const Color &color) { animations[0]->setColor(color); }
	const Texture * getTexture () const { return animations[0]->getTexture(); }
	const IntRect & getTextureRect () const { return animations[0]->getTextureRect(); }
	const Color & getColor () const { return animations[0]->getColor(); }
	FloatRect getLocalBounds () const { return animations[0]->getLocalBounds(); }
	FloatRect getGlobalBounds () const { return animations[0]->getGlobalBounds(); }
	void setPosition (float x, float y) { animations[0]->setPosition(x, y); }
	void setPosition (const Vector2f &position) { animations[0]->setPosition(position); }
	void setRotation (float angle) { animations[0]->setRotation(angle); }
	void setScale (float factorX, float factorY) { animations[0]->setScale(factorX, factorY); }
	void setScale (const Vector2f &factors) { animations[0]->setScale(factors); }
	void setOrigin (float x, float y) { animations[0]->setOrigin(x, y); }
	void setOrigin (const Vector2f &origin) { animations[0]->setOrigin(origin); }
	const Vector2f & getPosition () const { return animations[0]->getPosition(); }
	float getRotation () const { return animations[0]->getRotation(); }
	const Vector2f & getScale () const { return animations[0]->getScale(); }
	const Vector2f & getOrigin () const { return animations[0]->getOrigin(); }
	void move (float offsetX, float offsetY) { animations[0]->move(offsetX, offsetY); }
	void move (const Vector2f &offset) { animations[0]->move(offset); }
	void rotate (float angle) { animations[0]->rotate(angle); }
	void scale (float factorX, float factorY) { animations[0]->scale(factorX, factorY); }
	void scale (const Vector2f &factor) { animations[0]->scale(factor); }
	const Transform & getTransform () const { return animations[0]->getTransform(); }
	const Transform & getInverseTransform () const { return animations[0]->getInverseTransform(); }
	
	void setSize(size_t size);
	void addAnimation(size_t i, Animation* anim);
	void play(size_t i);
	size_t currentAnimation() const;
	void stop();
	Animation& operator[](size_t i);
	virtual void draw(RenderTarget& target, RenderStates states) const;
	
private:
	void unifySpritePointers();
	
private:
	vector<unique_ptr<Animation>> animations;
	size_t current = 0;
};

#endif //ANIMATION_HOLDER_H