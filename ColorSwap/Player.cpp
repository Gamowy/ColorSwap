#include "ColorSwap.h"
#include "Player.h"

void Player::move()
{
	ballSpeed.y += GRAVITY;
	if (Keyboard::isKeyPressed(Keyboard::Space) && canJump==true) 
	{
		ballSpeed.y = JUMP_HEIGHT;
		canJump = false;
		std::cout << "Player position x:" << ball.getPosition().x << ", y:" << ball.getPosition().y << std::endl;
	}
	if (Keyboard::isKeyPressed(Keyboard::Space) == false)
	{
		canJump = true;
	}
	ball.move(ballSpeed);

}

Player::Player()
{
	ball.setRadius(12.5f);
	ball.setFillColor(Color::White);
	ball.setPosition(Vector2f(WINDOW_WIDTH/2.f - ball.getRadius(), 30000.f));
	ballSpeed.x = 0.f;
	ballSpeed.y = 0.f;
	ball.setOrigin(ball.getRadius(), ball.getRadius());
	canJump = true;
}

Player::~Player()
{
}

Vector2f Player::getPosition()
{
	return ball.getPosition();
}

Vector2f Player::getSpeed()
{
	return ballSpeed;
}

void Player::update()
{
	move();
}

void Player::render(RenderTarget* target)
{
	target->draw(ball);
}


