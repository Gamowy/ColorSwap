#pragma once
#include "ColorSwap.h"

using namespace sf;

class Player
{
private:

	CircleShape ball;
	RectangleShape hitbox;
	Color ballColor;
	Vector2f ballSpeed;
	bool canJump;

	//Private methods
	void move();

public:
	Player();
	virtual ~Player();

	Vector2f getPosition();
	Vector2f getSpeed();
	FloatRect getBounds();
	Color getColor();
	RectangleShape getHitbox();
	void colorChange();
	void update();
	void render(RenderTarget* target);
};

