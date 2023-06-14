#pragma once
#include "ColorSwap.h"
#include "Item.h"

using namespace sf;


class Obstacle
{
protected:
	float yPosition;
	Item* star;
	Item* colorSwitch;

public:
	Obstacle(float yPosition, Texture& starTexture, Texture& colorSwitchTexture);
	virtual ~Obstacle();

	float getYPosition();
	bool checkStarColision(FloatRect playerBounds);
	bool checkSwitchColision(FloatRect playerBounds);
	virtual bool checkObstacleColision(RectangleShape player, Color playerColor) = 0;
	virtual void update() = 0;
	virtual void renderObstacle(RenderTarget* target) = 0;
	void render(RenderTarget* target);
};