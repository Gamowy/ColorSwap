#include "ColorSwap.h"
#include "Obstacle.h"

Obstacle::Obstacle(float yPosition, Texture& starTexture, Texture& colorSwitchTexture)
{
	this->yPosition = yPosition;
	star = new Item(yPosition, starTexture);
	colorSwitch = new Item(yPosition - 100.f, colorSwitchTexture);
}

Obstacle::~Obstacle()
{
	delete star;
	delete colorSwitch;
}  

float Obstacle::getYPosition()
{
	return yPosition;
}

bool Obstacle::checkStarColision(FloatRect playerBounds)
{
	if (star != nullptr && playerBounds.intersects(star->getBounds())) 
	{
		delete star;
		star = nullptr;
		return true;
	}
	return false;
}

bool Obstacle::checkSwitchColision(FloatRect playerBounds)
{
	if (colorSwitch != nullptr && playerBounds.intersects(colorSwitch->getBounds())) 
	{
		delete colorSwitch;
		colorSwitch = nullptr;
		return true;
	}
	return false;
}

//Pure virtual function
bool Obstacle::checkObstacleColision(RectangleShape playerBounds, Color playerColor)
{
	return false;
}

void Obstacle::update()
{
}

void Obstacle::render(RenderTarget* target)
{
	if (star != nullptr) 
	{
		star->render(target);
	}
	if (colorSwitch != nullptr)
	{
		colorSwitch->render(target);
	}
}
