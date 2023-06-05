#pragma once
#include "ColorSwap.h"

using namespace sf;

class Player
{
private:
	CircleShape ball;
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
	void update();
	void render(RenderTarget* target);
};

