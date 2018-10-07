#include "layer.h"

void Layer::addEntity(Entity* e)
{
	auto it = find_if(entities.begin(), entities.end(), [&e](unique_ptr<Entity>& i)
	{
		return (i.get() == e);
	});
	if (it != entities.end())
		ErrorHandler("Trying to insert Entity twice");
	entities.push_back(move(unique_ptr<Entity>(e)));
}

void Layer::removeEntity(Entity* e)
{
	auto it = find_if(entities.begin(), entities.end(), [&e](unique_ptr<Entity>& i)
	{
		return (i.get() == e);
	});
	if (it != entities.end())
	{
		ErrorHandler("Trying to delete non-existing Entity");
		return;
	}
	entities.erase(it);
}

void Layer::draw(RenderTarget& target, RenderStates states) const
{
	for (auto& it: entities)
	{
		target.draw(*it);
	}
}

void Layer::update(Time dt)
{
	for (auto& it: entities)
	{
		it->update(dt);
	}
}
