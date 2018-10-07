#ifndef WALL_H
#define WALL_H
#include "entity.h"
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RenderTarget.hpp>

using namespace sf;
using namespace std;

class Wall: public Entity
{
public:
	Wall(Texture& texture, IntRect rect, Vector2f position): sprite(texture, rect)
	{
		isSolid = true;
		sprite.setPosition(position);
	}
	virtual void draw(RenderTarget& target, RenderStates states) const final
	{
		target.draw(sprite, states);
	}
	
private:
	Sprite sprite;
};

#endif //WALL_H