#include "ColorSwap.h"
#include "ObstacleWindmill.h"
#include "Collision.h"

ObstacleWindmill::ObstacleWindmill(float yPosition, Texture& starTexture, Texture& colorSwitchTexture):Obstacle(yPosition, starTexture, colorSwitchTexture)
{
	Vector2f rectangleSize(25, 150);
	Color colors[4] = { COLOR_SWAP_CYAN, COLOR_SWAP_PURPLE, COLOR_SWAP_RED, COLOR_SWAP_YELLOW };
	bool isOnLeftSide;
	isOnLeftSide = sidePicker(gen);

	for (int index = 0; index <= 3; index++)
	{
		rectangles[index].setRotation(index *90);
		rectangles[index].setSize(rectangleSize);
		rectangles[index].setFillColor(colors[index]);
		if (isOnLeftSide)
		{
			rectangles[index].setPosition(WINDOW_WIDTH * 0.3f, yPosition);
		}
		else
		{
			rectangles[index].setPosition(WINDOW_WIDTH * 0.7f, yPosition);
		}
	}

	if (isOnLeftSide)
	{
		rotationSpeed = -1.0f;
	}
	else
	{
		rotationSpeed = 1.0f;
	}
}

ObstacleWindmill::~ObstacleWindmill()
{
}

bool ObstacleWindmill::checkObstacleColision(RectangleShape player, Color playerColor)
{
	for (int index = 0; index <= 3; index++)
	{
		if (collision::areColliding(rectangles[index], player) && playerColor != rectangles[index].getFillColor())
		{
			return true;
			std::cout << "Game over!" << std::endl;
		}
	}
	return false;
}

void ObstacleWindmill::update()
{
	for (int index = 0; index <= 3; index++)
	{
		rectangles[index].setRotation(rectangles[index].getRotation() + rotationSpeed);
	}
}

void ObstacleWindmill::renderObstacle(RenderTarget* target)
{
	for (int index = 0; index <= 3; index++)
	{
		target->draw(rectangles[index]);
	}
}