#pragma once
#include "ColorSwap.h"

using namespace sf;

class Player
{
private:
	CircleShape ball;
	Vector2f ballSpeed;
	bool canJump;
	View view;
	//Private functions
	void move();

public:
	Player();
	virtual ~Player();

	void update();
	void render(RenderTarget* target);
	View getView();
};

