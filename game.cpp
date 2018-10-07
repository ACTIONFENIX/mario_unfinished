#include "game.h"

Game::Game(): window(VideoMode(320, 240), "Game")
{
	loadResources();
	vector<string> map = 
	{
		{"========================================"},
		{"=                                      ="},
		{"=                                      ="},
		{"=                                      ="},
		{"=                                      ="},
		{"=                                      ="},
		{"=                                      ="},
		{"=                                      ="},
		{"=                                      ="},
		{"=             ==                       ="},
		{"=            =  =                      ="},
		{"=                                      ="},
		{"=                                      ="},
		{"=   @                                  ="},
		{"########################################"}
	};
	loadMap(map);
}

void Game::run()
{
	Time dt = Time::Zero;
	while(window.isOpen())
	{
		clock.restart();
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				window.close();
			}
		}
		player->update(dt);
		render();
		dt = clock.getElapsedTime();
		while((dt = clock.getElapsedTime()).asSeconds() < frameDuration);
	}
}

void Game::loadResources()
{
	texture.loadFromFile("res/textures.png");
	playerTexture.loadFromFile("res/mario.png");
	float frameSpeed = 0.1;
	
	Animation* WalkingRight = new Animation;
	WalkingRight->setTexture(playerTexture);
	WalkingRight->setFrameCount(3);
	WalkingRight->setFrameRect(IntRect(240, 0, 16, 16));
	WalkingRight->setDistance(30);
	WalkingRight->setFrameSpeed(frameSpeed);
	
	Animation* WalkingLeft = new Animation;
	WalkingLeft->setTexture(playerTexture);
	WalkingLeft->setFrameCount(3);
	WalkingLeft->setFrameRect(IntRect(254, 0, -16, 16));
	WalkingLeft->setDistance(30);
	WalkingLeft->setFrameSpeed(frameSpeed);
	
	Animation* StandingRight = new Animation;
	StandingRight->setTexture(playerTexture);
	StandingRight->setFrameRect(IntRect(211, 0, 16, 16));
	
	Animation* StandingLeft = new Animation;
	StandingLeft->setTexture(playerTexture);
	StandingLeft->setFrameRect(IntRect(181, 0, 16, 16));
	
	Animation* JumpingRight = new Animation;
	JumpingRight->setTexture(playerTexture);
	JumpingRight->setFrameRect(IntRect(359, 0, 16, 16));
	
	Animation* JumpingLeft = new Animation;
	JumpingLeft->setTexture(playerTexture);
	JumpingLeft->setFrameRect(IntRect(29, 0, 16, 16));
	
	AnimationHolder* animations = new AnimationHolder(Player::AnimationsCount);
	animations->addAnimation(Player::WalkingRight, WalkingRight);
	animations->addAnimation(Player::WalkingLeft, WalkingLeft);
	animations->addAnimation(Player::StandingRight, StandingRight);
	animations->addAnimation(Player::StandingLeft, StandingLeft);
	animations->addAnimation(Player::JumpingRight, JumpingRight);
	animations->addAnimation(Player::JumpingLeft, JumpingLeft);
	
	player.reset(new Player(animations));
}

void Game::loadMap(vector<string>& map_lvl)
{
	map = move(map_lvl);
	constexpr char MWall = '=';
	constexpr char MGround = '#';
	constexpr char MPlayer = '@';
	constexpr char MEmpty = ' ';
	IntRect WallRect(16, 0, 16, 16);
	IntRect GroundRect(0, 0, 16, 16);
	for (size_t i = 0; i < map.size(); ++i)
	{
		for (size_t j = 0; j < map[i].size(); ++j)
		{
			switch(map[i][j])
			{
				case MWall:
				{
					layer.addEntity(new Wall(texture, WallRect, {j * WallRect.width, i * WallRect.height}));
					break;
				}
				case MGround:
				{
					layer.addEntity(new Ground(texture, GroundRect, {j * WallRect.width, i * WallRect.height}));
					break;
				}
				case MPlayer:
				{
					player->spawn({j * 16, i * 16});
					player->setSpeed(40);
					break;
				}
				case MEmpty:
				{
					break;
				}
				default:
				{
					ErrorHandler("Unknown type of cell");
				}
			}
		}
	}
	view.setSize(320, 240);
	window.setView(view);
	worldBounds = {0.f, 0.f, 640.f, 240.f};
}

void Game::render()
{
	window.clear(Color::White);
	window.draw(layer);
	window.draw(*player);
	updateView();
	window.display();
}

void Game::update(Time dt)
{
	player->update(dt);
	layer.update(dt);
}

void Game::processInput()
{
	Event event;
	while (window.pollEvent(event))
	{
		if (event.type == Event::KeyPressed)
		{
			if (event.key.code == Keyboard::Escape)
			{
				window.close();
			}
		}
	}
}

void Game::updateView()
{
	Vector2f position = player->getPosition();
	if (position.x - view.getSize().x / 2.f < worldBounds.left)
		position.x = worldBounds.left + view.getSize().x / 2.f;
	if (position.x + view.getSize().x / 2.f > worldBounds.left + worldBounds.width)
		position.x = worldBounds.left + worldBounds.width - view.getSize().x / 2.f;
	if (position.y - view.getSize().y / 2.f < worldBounds.top)
		position.y = worldBounds.top + view.getSize().y / 2.f;
	if (position.y + view.getSize().y / 2.f > worldBounds.top + worldBounds.height)
		position.y = worldBounds.top + worldBounds.height - view.getSize().y / 2.f;
	view.setCenter(position);
	window.setView(view);
}
