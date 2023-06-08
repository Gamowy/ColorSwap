#pragma once
#include "ColorSwap.h"

using namespace sf;
//Integer distribution for seting random ball color
static std::uniform_int_distribution<int> colorRandomPick(0, 3);

class Player
{
private:
	CircleShape ball;
	RectangleShape hitbox;
	Color ballColor;
	Vector2f ballSpeed;
	bool startedJumping;
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
	void switchColor();
	void update();
	void render(RenderTarget* target);
};

