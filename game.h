#ifndef GAME_H
#define GAME_H
#include <vector>
#include <string>
#include <memory>
#include <iostream>
#include "player.h"
#include "layer.h"
#include "wall.h"
#include "ground.h"
#include "error_handler.h"
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/View.hpp>

using namespace sf;
using namespace std;

//All pointers -> unique_ptr

class Game
{
public:
	Game();
	void run();
	const char& mapCell(size_t row, size_t column) const
	{
		return map[row][column];
	}
	
private:
	void loadResources();
	void loadMap(vector<string>& map);
	void render();
	void update(Time dt);
	void processInput();
	void updateView();
	
private:
	RenderWindow window;
	FloatRect worldBounds;
	View view;
	Texture texture;
	Texture playerTexture;
	vector<string> map;
	static constexpr unsigned lockFPS = 60;
	static constexpr float frameDuration = 1.f / lockFPS;
	Clock clock;
	Layer layer;
	unique_ptr<Player> player;
};

#endif //GAME_H