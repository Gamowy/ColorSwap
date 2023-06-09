#include "ColorSwap.h"
#include "Player.h"


void Player::move(RenderWindow* window)
{
	if (startedJumping)
	{
		ballSpeed.y += GRAVITY;
	}
	if ( (Keyboard::isKeyPressed(Keyboard::Space) || (Mouse::isButtonPressed(Mouse::Left) && checkMousePosition(window)==true)) && canJump == true)
	{
		ballSpeed.y = JUMP_HEIGHT;
		canJump = false;
		startedJumping = true;
	}
	if (Keyboard::isKeyPressed(Keyboard::Space)==false && Mouse::isButtonPressed(Mouse::Left) == false)
	{
		canJump = true;
	}
	ball.move(ballSpeed);
	hitbox.move(ballSpeed);
}

bool Player::checkMousePosition(RenderWindow* window)
{
	if (Mouse::getPosition(*window).x >= 0 && Mouse::getPosition(*window).x<=WINDOW_WIDTH &&
		Mouse::getPosition(*window).y>=0 && Mouse::getPosition(*window).y<=WINDOW_HEIGHT)
	{
		return true;
	}
	return false;
}

Player::Player()
{
	
	hitbox.setSize(Vector2f(22.5f,22.5f));
	hitbox.setOrigin(hitbox.getSize().x/2.f, hitbox.getSize().y / 2.f);
	switchColor();
	hitbox.setPosition(WINDOW_WIDTH/2.f - hitbox.getSize().x / 2.f, 100000.f);
	ballSpeed.x = 0.f;
	ballSpeed.y = 0.f;
	startedJumping = false;
	canJump = true;

	ball.setRadius(13.f);
	ball.setPosition(WINDOW_WIDTH / 2.f - ball.getRadius(), 100000.f);
	ball.setOrigin(ball.getRadius(), ball.getRadius());
}

Player::~Player()
{
}

Vector2f Player::getPosition()
{
	return hitbox.getPosition();
}

Vector2f Player::getSpeed()
{
	return ballSpeed;
}

FloatRect Player::getBounds()
{
	return hitbox.getGlobalBounds();
}

Color Player::getColor()
{
	return ballColor;
}

RectangleShape Player::getHitbox()
{
	return hitbox;
}

void Player::switchColor()
{
	//Pick random color
	int RandomNumber = colorRandomPick(gen);
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

void Player::update(RenderWindow* window)
{
	move(window);
}

void Player::render(RenderTarget* target)
{
	target->draw(ball);
}