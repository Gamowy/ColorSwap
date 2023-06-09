#include "ColorSwap.h"
#include "ObstacleRingOfRectangles.h"

ObstacleRingOfRectangles::ObstacleRingOfRectangles(float yPosition, Texture& starTexture, Texture& colorSwitchTexture) : Obstacle(yPosition, starTexture, colorSwitchTexture)
{
	rotationSpeed = 1.5f;
	center.x = WINDOW_WIDTH / 2.f;
	center.y = yPosition;

	star->movePosition(-20.f);
	colorSwitch->movePosition(-75.f);

	for (int index = 0; index <= 11; index++)
	{
		rectangles[index].setSize(Vector2f(25.f,25.f));
		rectangles[index].setOrigin(rectangles[index].getSize().x/2.f - 90.f, rectangles[index].getSize().y / 2.f);
		rectangles[index].setPosition(center.x-rectangles[index].getSize().x/2, center.y);
		rectangles[index].setRotation(index*30);

		if (index <= 2)
		{
			rectangles[index].setFillColor(COLOR_SWAP_CYAN);
		}
		else if (index > 2 && index <= 5)
		{
			rectangles[index].setFillColor(COLOR_SWAP_PURPLE);
		}
		else if (index > 5 && index <= 8)
		{
			rectangles[index].setFillColor(COLOR_SWAP_RED);
		}
		else if(index>8&&index<=11)
		{
			rectangles[index].setFillColor(COLOR_SWAP_YELLOW);
		}

	}

}

ObstacleRingOfRectangles::~ObstacleRingOfRectangles()
{

}

bool ObstacleRingOfRectangles::checkObstacleColision(RectangleShape player, Color playerColor)
{
	for (int index = 0; index <= 11; index++)
	{
		if (collision::areColliding(rectangles[index], player) && playerColor != rectangles[index].getFillColor())
		{
			return true;
		}
	}
	return false;
}

void ObstacleRingOfRectangles::update()
{
	for (int index = 0; index <= 11; index++)
	{
		rectangles[index].setRotation(rectangles[index].getRotation() + rotationSpeed);
	}
}

void ObstacleRingOfRectangles::renderObstacle(RenderTarget* target)
{
	for (int index = 0; index <= 11; index++)
	{
		target->draw(rectangles[index]);
	}
}