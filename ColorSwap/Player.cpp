#include "ColorSwap.h"
#include "Player.h"

void Player::move()
{
	ballSpeed.y += GRAVITY;
	if (Keyboard::isKeyPressed(Keyboard::Space) and canJump==true) 
	{
		ballSpeed.y = JUMP_HEIGHT;
		canJump = false;
	}
	if (Keyboard::isKeyPressed(Keyboard::Space) == false)
	{
		canJump = true;
	}
	ball.move(ballSpeed);
}

Player::Player()
{
	ball.setRadius(10.f);
	ball.setFillColor(Color::White);
	ball.setPosition(Vector2f(WINDOW_WIDTH/2.f - ball.getRadius(), 0.875f * WINDOW_HEIGHT));
	ballSpeed.x = 0.f;
	ballSpeed.y = 0.f;
	canJump = true;
}

Player::~Player()
{
}

void Player::update()
{
	move();
}

void Player::render(RenderTarget* target)
{
	target->draw(ball);
}
