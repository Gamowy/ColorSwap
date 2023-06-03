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

bool Obstacle::checkStarColision(FloatRect playerBounds)
{
	if (playerBounds.intersects(star->getBounds())) 
	{
		return true;
	}
	return false;
}

bool Obstacle::checkSwitchColisio(FloatRect playerBounds)
{
	if (playerBounds.intersects(colorSwitch->getBounds())) 
	{
		return true;
	}
	return false;
}

//Pure virtual function
bool Obstacle::checkObstacleColision(FloatRect playerBounds)
{
	return false;
}

void Obstacle::update()
{
}

void Obstacle::render(RenderTarget* target)
{
	star->render(target);
	colorSwitch->render(target);
}
