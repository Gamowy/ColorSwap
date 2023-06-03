#pragma once
#include "ColorSwap.h"
#include "Item.h"

using namespace sf;

class Obstacle
{
private:
	float yPosition;
	Item* star;
	Item* colorSwitch;

public:
	Obstacle(float yPosition, Texture& starTexture, Texture& colorSwitchTexture);
	virtual ~Obstacle();

	float getYPosition();
	bool checkStarColision(FloatRect playerBounds);
	bool checkSwitchColision(FloatRect playerBounds);
	virtual bool checkObstacleColision(FloatRect playerBounds);
	void update();
	void render(RenderTarget* target);
};

