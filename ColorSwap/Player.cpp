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
	ColorChange();
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

void Player::ColorChange()
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> distribution(0, 3);
	int RandomNumber = distribution(gen);
	switch (RandomNumber)
	{
	case 0:
		if (ballColor != COLOR_SWAP_CYAN)
			ballColor = COLOR_SWAP_CYAN;
		else
			ballColor = COLOR_SWAP_PURPLE;
		break;
	case 1:
		if (ballColor != COLOR_SWAP_PURPLE)
			ballColor = COLOR_SWAP_PURPLE;
		else
			ballColor = COLOR_SWAP_YELLOW;
		break;
	case 2:
		if (ballColor != COLOR_SWAP_YELLOW)
			ballColor = COLOR_SWAP_YELLOW;
		else
			ballColor = COLOR_SWAP_RED;
		break;
	case 3:
		if (ballColor != COLOR_SWAP_RED)
			ballColor = COLOR_SWAP_RED;
		else
			ballColor = COLOR_SWAP_CYAN;
		break;
	}
	ball.setFillColor(ballColor);
}

void Player::update()
{
	move();
}

void Player::render(RenderTarget* target)
{
	target->draw(ball);
}


