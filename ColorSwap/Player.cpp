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
	ballColor = COLOR_SWAP_CYAN;
	ball.setFillColor(ballColor);
	ball.setPosition(WINDOW_WIDTH/2.f - ball.getRadius(), 100000.f);
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

FloatRect Player::getBounds()
{
	return ball.getGlobalBounds();
}

void Player::update()
{
	move();
}

void Player::render(RenderTarget* target)
{
	target->draw(ball);
}


