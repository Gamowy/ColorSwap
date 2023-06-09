#include "ColorSwap.h"
#include "ObstacleWindmill.h"

ObstacleWindmill::ObstacleWindmill(float yPosition, Texture& starTexture, Texture& colorSwitchTexture) : Obstacle(yPosition, starTexture, colorSwitchTexture)
{
	int windMillVariation = variation(gen);
	Color colors[4] = { COLOR_SWAP_CYAN, COLOR_SWAP_PURPLE, COLOR_SWAP_RED, COLOR_SWAP_YELLOW };
	colorSwitch->movePosition(-100.f);
	rotationSpeed = -1.0f;

	if (windMillVariation == 0)
	{
		rotationSpeed = 1.0f;
		rectCount = 8;
	}
	else
	{
		rectCount = 4;
	}
	rectangles = new RectangleShape[rectCount];

	for (int index = 0; index < rectCount; index++)
	{
		rectangles[index].setRotation(index * 90.f);
		rectangles[index].setSize(Vector2f(25.f, 150.f));
		rectangles[index].setFillColor(colors[index % 4]);
		switch (windMillVariation)
		{
			//double windmill
			case 0:	
				if (index < 4)
				{
					rectangles[index].setPosition(WINDOW_WIDTH * 0.3f, yPosition);
				}
				else
				{
					rectangles[index].setPosition(WINDOW_WIDTH * 0.7f, yPosition);
				}
				break;
			//left windmill
			case 1:
				rectangles[index].setPosition(WINDOW_WIDTH * 0.3f, yPosition);
				break;
			//right windmill
			case 2:
				rectangles[index].setPosition(WINDOW_WIDTH * 0.7f, yPosition);
				break;
		}
	}

	if (windMillVariation == 0)
	{
		rectangles[5].setFillColor(colors[3]);
		rectangles[7].setFillColor(colors[1]);
	}
}

ObstacleWindmill::~ObstacleWindmill()
{
	delete[] rectangles;
}

bool ObstacleWindmill::checkObstacleColision(RectangleShape player, Color playerColor)
{
	for (int index = 0; index < rectCount; index++)
	{
		if (collision::areColliding(rectangles[index], player) && playerColor != rectangles[index].getFillColor())
		{
			return true;
		}
	}
	return false;
}

void ObstacleWindmill::update()
{
	for (int index = 0; index < rectCount; index++)
	{
		if (index < 4)
		{
			rectangles[index].setRotation(rectangles[index].getRotation() + rotationSpeed);
		}
		else
		{
			rectangles[index].setRotation(rectangles[index].getRotation() - rotationSpeed);
		}
	}
}

void ObstacleWindmill::renderObstacle(RenderTarget* target)
{
	for (int index = 0; index < rectCount; index++)
	{
		target->draw(rectangles[index]);
	}
}