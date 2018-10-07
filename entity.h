#ifndef ENTITY_H
#define ENTITY_H
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/System/Time.hpp>

using namespace sf;
using namespace std;

class Entity: public Drawable
{
public:
	Entity() = default;
	virtual ~Entity() = default;
	virtual void update(Time dt) {};
	virtual void draw(RenderTarget& target, RenderStates states) const override = 0;
	
protected:
	Vector2f velocity{0.f, 0.f};
	bool isSolid = false;
};

#endif //ENTITY_H