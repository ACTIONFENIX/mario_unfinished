#include "player.h"

void Player::draw(RenderTarget& target, RenderStates states) const
{
	target.draw(*animations, states);
}

void Player::update(Time dt)
{
	if (Keyboard::isKeyPressed(Keyboard::D))
	{
		velocity.x = speed;
		velocity.y = 0.f;
		animations->play(WalkingRight);
	}
	else if (Keyboard::isKeyPressed(Keyboard::A))
	{
		velocity.x = -speed;
		velocity.y = 0.f;
		animations->play(WalkingLeft);
	}
	else if (!Keyboard::isKeyPressed(Keyboard::D) && !Keyboard::isKeyPressed(Keyboard::A) && !Keyboard::isKeyPressed(Keyboard::Space))
	{
		const AnimationType& type = static_cast<const AnimationType>(animations->currentAnimation());
		if (type == WalkingRight || type == StandingRight)
		{
			animations->play(StandingRight);
		}
		else
		{
			animations->play(StandingLeft);
		}
		velocity.x = 0.f;
		velocity.y = 0.f;
		animations->stop();
	}
	if (Keyboard::isKeyPressed(Keyboard::Space))
	{
		//Jump
	}
	
	position += velocity * dt.asSeconds();
	animations->setPosition(position);
}
