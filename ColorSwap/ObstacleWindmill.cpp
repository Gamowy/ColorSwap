#include "ColorSwap.h"
#include "ObstacleWindmill.h"

ObstacleWindmill::ObstacleWindmill(float yPosition, Texture& starTexture, Texture& colorSwitchTexture):Obstacle(yPosition, starTexture, colorSwitchTexture)
{
	Vector2f rectangleSize(25, 150);
	Color colors[4] = { COLOR_SWAP_CYAN, COLOR_SWAP_PURPLE, COLOR_SWAP_RED, COLOR_SWAP_YELLOW };

	for (int index = 0; index <= 3; index++)
	{
		rectangles[index].setRotation(index *90);
		rectangles[index].setSize(rectangleSize);
		rectangles[index].setFillColor(colors[index]);
		rectangles[index].setPosition(WINDOW_WIDTH * 0.25, yPosition);
	}
}

ObstacleWindmill::~ObstacleWindmill()
{
}

bool ObstacleWindmill::checkObstacleColision(FloatRect playerBounds, Color playerColor)
{
	for (int index = 0; index <= 3; index++)
	{
		if (playerBounds.intersects(rectangles[index].getGlobalBounds()) && playerColor!=rectangles[index].getFillColor())
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
		rectangles[index].setRotation(rectangles[index].getRotation() - 1);
	}
}

void ObstacleWindmill::renderObstacle(RenderTarget* target)
{
	for (int index = 0; index <= 3; index++)
	{
		target->draw(rectangles[index]);
	}
}

void ObstacleWindmill::render(RenderTarget* target)
{

	renderObstacle(target);

	if (star != nullptr)
	{
		star->render(target);
	}
	if (colorSwitch != nullptr)
	{
		colorSwitch->render(target);
	}
}
