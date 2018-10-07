#ifndef PLAYER_H
#define PLAYER_H
#include "entity.h"
#include "animation_holder.h"
#include <memory>
#include <vector>
#include <string>
#include <SFML/System/Time.hpp>
#include <SFML/Window/Keyboard.hpp>

using namespace sf;
using namespace std;

class Game;

class Player: public Entity
{
public:
	enum AnimationType
	{
		WalkingRight,
		WalkingLeft,
		StandingRight,
		StandingLeft,
		JumpingRight,
		JumpingLeft,
		AnimationsCount
	};
	
public:
	Player(AnimationHolder* anims): animations(move(unique_ptr<AnimationHolder>(anims))) {}
	void update(Time dt);
	
public:
	friend class Game;
	
private:
	virtual void draw(RenderTarget& target, RenderStates states) const override;
	void spawn(Vector2f pos)
	{
		position = pos;
	}
	void setSpeed(float playerSpeed)
	{
		speed = playerSpeed;
	}
	const Vector2f& getPosition() const
	{
		return position;
	}
	
private:
	unique_ptr<AnimationHolder> animations;
	Vector2f position;
	Vector2f velocity{0.f, 0.f};
	float speed;
	char curCell;
};

#endif //PLAYER_H