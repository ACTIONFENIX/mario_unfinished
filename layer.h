#ifndef LAYER_H
#define LAYER_H
#include "entity.h"
#include "error_handler.h"
#include <memory>
#include <vector>
#include <algorithm>
#include <SFML/System/Time.hpp>
#include <SFML/Graphics/RenderTarget.hpp>

using namespace sf;
using namespace std;

class Layer: public Drawable
{
public:
	void addEntity(Entity* e);
	void removeEntity(Entity* e);
	void update(Time dt);
	const vector<unique_ptr<Entity>>& entitiesList() const
	{
		return entities;
	}

private:
	virtual void draw(RenderTarget& target, RenderStates states) const final override;
	
private:
	vector<unique_ptr<Entity>> entities;
};

#endif //LAYER_H