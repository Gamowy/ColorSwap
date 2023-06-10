#include "ColorSwap.h"
#include "ObstacleLine.h"
ObstacleLine::ObstacleLine(float yPosition, Texture& starTexture, Texture& colorSwitchTexture) : Obstacle(yPosition, starTexture, colorSwitchTexture)
{
	Color colors[4] = { COLOR_SWAP_CYAN, COLOR_SWAP_PURPLE, COLOR_SWAP_RED, COLOR_SWAP_YELLOW };
	center.x = WINDOW_WIDTH / 2.f;
	center.y = yPosition;
	rectangleSpeed.x = 3.f;

	star->movePosition(-100.f);
	colorSwitch->movePosition(-180.f);

	for (int index = 0; index <= 3; index++)
	{
		rectangles[index].setFillColor(colors[index]);
		rectangles[index].setSize(Vector2f(20.f, 150.f));
		rectangles[index].rotate(90.f);
		rectangles[index].setPosition(center.x - 161.f + index * 150.f, center.y);
	}

	rectangles[4].setFillColor(COLOR_SWAP_RED);
	rectangles[4].setSize(Vector2f(20.f, 150.f));
	rectangles[4].rotate(90.f);
	rectangles[4].setPosition(center.x - 311.f, center.y);

	for (int index = 5; index <= 8; index++)
	{
		rectangles[index].setFillColor(colors[index-5]);
		rectangles[index].setSize(Vector2f(20.f, 150.f));
		rectangles[index].rotate(90.f);
		rectangles[index].setPosition(center.x - 161.f + (index-5) * 150.f, center.y - 180.f);
	}

	rectangles[9].setFillColor(COLOR_SWAP_PURPLE);
	rectangles[9].setSize(Vector2f(20.f, 150.f));
	rectangles[9].rotate(90.f);
	rectangles[9].setPosition(center.x + 439.f, center.y - 180.f);
	
}

ObstacleLine::~ObstacleLine()
{
}

bool ObstacleLine::checkObstacleColision(RectangleShape player, Color playerColor)
{
	for (int index = 0; index <= 9; index++)
	{
		if (collision::areColliding(rectangles[index], player) && playerColor != rectangles[index].getFillColor())
		{
			return true;
		}
	}
	return false;
}

void ObstacleLine::update()
{
	rectangleSpeed.x = 3.f;
	for (int index = 0; index <= 4; index++)
	{
		rectangles[index].move(rectangleSpeed);
		if (rectangles[index].getPosition().x == center.x + 439.f)
		{
			rectangles[index].setPosition(center.x - 311.f, center.y);
		}
	}
	rectangleSpeed.x = -3.f;
	for (int index = 5; index <= 9; index++)
	{
		rectangles[index].move(rectangleSpeed);
		if (rectangles[index].getPosition().x == center.x - 311.f)
		{
			rectangles[index].setPosition(center.x + 439.f, center.y - 180.f);
		}
	}
}

void ObstacleLine::renderObstacle(RenderTarget* target)
{
	for (int index = 0; index <= 9; index++)
	{
		target->draw(rectangles[index]);
	}
}