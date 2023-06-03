#include "ColorSwap.h"
#include "Obstacle.h"

Obstacle::Obstacle(float yPosition, Texture& starTexture, Texture& colorSwitchTexture)
{
	star.initItem(yPosition, starTexture);
	colorSwitch.initItem(yPosition - 100.f, colorSwitchTexture);
}

Obstacle::~Obstacle()
{
}  

bool Obstacle::checkStarColision(FloatRect playerBounds)
{
	if (playerBounds.intersects(star.getBounds())) 
	{
		return true;
	}
	return false;
}

bool Obstacle::checkSwitchColision(FloatRect playerBounds)
{
	if (playerBounds.intersects(colorSwitch.getBounds())) 
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
	star.render(target);
	colorSwitch.render(target);
}
