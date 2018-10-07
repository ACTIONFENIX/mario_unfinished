#ifndef ANIMATION_H
#define ANIMATION_H
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <memory>
#include <iostream>

class AnimationHolder;

using namespace sf;
using namespace std;

class Animation: public Drawable, public Transformable
{
public:
	Animation(): firstFrame(IntRect()), frameCount(1.f), distance(0), frameSpeed(0.f) {}
	Animation(Texture& texture, const IntRect& firstFrameRect, unsigned framesCount = 1, unsigned framesDistance = 0, float framesSpeed = 0.f): firstFrame(firstFrameRect), frameCount(framesCount), distance(framesDistance), frameSpeed(framesSpeed)
	{
		sprite->setTexture(texture);
		sprite->setTextureRect(firstFrame);
	}
	virtual ~Animation() = default;
	void setTexture (const Texture &texture, bool resetRect = false) { sprite->setTexture(texture, resetRect); }
	void setTextureRect (const IntRect &rectangle) { sprite->setTextureRect(rectangle); }
	void setColor (const Color &color) { sprite->setColor(color); }
	const Texture * getTexture () const { return sprite->getTexture(); }
	const IntRect & getTextureRect () const { return sprite->getTextureRect(); }
	const Color & getColor () const { return sprite->getColor(); }
	FloatRect getLocalBounds () const { return sprite->getLocalBounds(); }
	FloatRect getGlobalBounds () const { return sprite->getGlobalBounds(); }
	void setPosition (float x, float y) { sprite->setPosition(x, y); }
	void setPosition (const Vector2f &position) { sprite->setPosition(position); }
	void setRotation (float angle) { sprite->setRotation(angle); }
	void setScale (float factorX, float factorY) { sprite->setScale(factorX, factorY); }
	void setScale (const Vector2f &factors) { sprite->setScale(factors); }
	void setOrigin (float x, float y) { sprite->setOrigin(x, y); }
	void setOrigin (const Vector2f &origin) { sprite->setOrigin(origin); }
	const Vector2f & getPosition () const { return sprite->getPosition(); }
	float getRotation () const { return sprite->getRotation(); }
	const Vector2f & getScale () const { return sprite->getScale(); }
	const Vector2f & getOrigin () const { return sprite->getOrigin(); }
	void move (float offsetX, float offsetY) { sprite->move(offsetX, offsetY); }
	void move (const Vector2f &offset) { sprite->move(offset); }
	void rotate (float angle) { sprite->rotate(angle); }
	void scale (float factorX, float factorY) { sprite->scale(factorX, factorY); }
	void scale (const Vector2f &factor) { sprite->scale(factor); }
	const Transform & getTransform () const { return sprite->getTransform(); }
	const Transform & getInverseTransform () const { return sprite->getInverseTransform(); }
	
	void setFrame(unsigned frame);
	unsigned getFrame() const;
	void reset();
	void setFrameCount(unsigned count);
	void setFrameRect(IntRect rect);
	void setDistance(unsigned distance);
	void setFrameSpeed(float speed);
	
private:
	virtual void draw(RenderTarget& target, RenderStates states) const override;
	
public:
	friend class AnimationHolder;
	
protected:
	mutable shared_ptr<Sprite> sprite{new Sprite};
	
private:
	mutable float frameNumber = 0.f;
	IntRect firstFrame;
	unsigned frameCount;
	unsigned distance;
	float frameSpeed;
};

#endif //ANIMATION_H