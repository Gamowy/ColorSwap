#include "ColorSwap.h"
#include "Obstacle.h"

Obstacle::Obstacle(Vector2f position, Texture starTexture, Texture colorSwitchTexture)
{
	star = new Item(position, starTexture);
	colorSwitch = new Item(Vector2f(position.x, position.y - 100.f), colorSwitchTexture);
}

Obstacle::~Obstacle()
{
}

void Obstacle::update()
{
}

void Obstacle::render(RenderTarget* target)
{
	star->render(target);
	colorSwitch->render(target);
}
