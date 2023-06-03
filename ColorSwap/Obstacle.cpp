#include "ColorSwap.h"
#include "Obstacle.h"

Obstacle::Obstacle(float yPosition, Texture& starTexture, Texture& colorSwitchTexture)
{
	star = new Item(yPosition, starTexture);
	colorSwitch = new Item(yPosition - 100.f, colorSwitchTexture);
}

Obstacle::~Obstacle()
{
	delete star;
	delete colorSwitch;
}

void Obstacle::update()
{
}

void Obstacle::render(RenderTarget* target)
{
	star->render(target);
	colorSwitch->render(target);
}
