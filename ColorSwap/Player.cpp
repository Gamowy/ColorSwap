#include "ColorSwap.h"
#include "Player.h"

void Player::move()
{
	ballSpeed.y += GRAVITY;
	if (Keyboard::isKeyPressed(Keyboard::Space) and canJump==true) 
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

	if (ball.getPosition().y <= view.getCenter().y + 0.3f * WINDOW_HEIGHT)
	{
		view.move(ballSpeed);
	}
}

Player::Player()
{
	ball.setRadius(10.f);
	ball.setFillColor(Color::White);
	ball.setPosition(Vector2f(WINDOW_WIDTH/2.f - ball.getRadius(), 0.875f * WINDOW_HEIGHT));
	ballSpeed.x = 0.f;
	ballSpeed.y = 0.f;
	canJump = true;
	view.setCenter(ball.getPosition().x, ball.getPosition().y - 0.3f * WINDOW_HEIGHT);
	view.setSize(WINDOW_WIDTH, WINDOW_HEIGHT);
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

View Player::getView()
{
	return view;
}
