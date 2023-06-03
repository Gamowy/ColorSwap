#pragma once
#include "ColorSwap.h"
#include "Item.h"

using namespace sf;

class Obstacle
{
private:
	Item* star;
	Item* colorSwitch;

public:
	Obstacle(Vector2f position, Texture starTexture, Texture colorSwitchTexture);
	virtual ~Obstacle();

	void update();
	void render(RenderTarget* target);
};

