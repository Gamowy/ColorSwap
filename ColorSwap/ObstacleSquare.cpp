#include "ColorSwap.h"
#include "ObstacleSquare.h"

ObstacleSquare::ObstacleSquare(float yPosition, Texture& starTexture, Texture& colorSwitchTexture) : Obstacle(yPosition, starTexture, colorSwitchTexture)
{
	center.x = WINDOW_WIDTH / 2.f;
	center.y = yPosition;
	rotationSpeed = 1.f;

	star->movePosition(-30.f);
	colorSwitch->movePosition(-120.f);

	rectangles[0].setFillColor(COLOR_SWAP_CYAN);
	rectangles[0].setSize(Vector2f(20.f, 180.f));
	rectangles[0].rotate(135.f);
	rectangles[0].setPosition(center.x - 10.f, center.y);
	rectangles[0].setOrigin(rectangles[0].getSize().x - 100.f, rectangles[0].getSize().y / 2.f - 10.f);
	
	
	rectangles[1].setFillColor(COLOR_SWAP_PURPLE);
	rectangles[1].setSize(Vector2f(20.f, 200.f));
	rectangles[1].rotate(45.f);
	rectangles[1].setPosition(center.x - 10.f, center.y);
	rectangles[1].setOrigin(rectangles[0].getSize().x - 100.f, rectangles[0].getSize().y / 2.f + 10.f);

	
	rectangles[2].setFillColor(COLOR_SWAP_RED);
	rectangles[2].setSize(Vector2f(20.f, 200.f));
	rectangles[2].rotate(45.f);
	rectangles[2].setPosition(center.x - 10.f, center.y);
	rectangles[2].setOrigin(rectangles[0].getSize().x + 100.f, rectangles[0].getSize().y / 2.f + 10.f);

	rectangles[3].setFillColor(COLOR_SWAP_YELLOW);
	rectangles[3].setSize(Vector2f(20.f, 220.f));
	rectangles[3].rotate(135.f);
	rectangles[3].setPosition(center.x - 10.f, center.y);
	rectangles[3].setOrigin(rectangles[0].getSize().x + 100.f, rectangles[0].getSize().y / 2.f + 10.f);
}

ObstacleSquare::~ObstacleSquare()
{
}

bool ObstacleSquare::checkObstacleColision(RectangleShape player, Color playerColor)
{
	for (int index = 0; index <= 3; index++)
	{
		if (collision::areColliding(rectangles[index], player) && playerColor != rectangles[index].getFillColor())
		{
			return true;
		}
	}
	return false;
}

void ObstacleSquare::update()
{
	for (int index = 0; index <= 3; index++)
	{
		rectangles[index].setRotation(rectangles[index].getRotation() + rotationSpeed);
	}
}

void ObstacleSquare::renderObstacle(RenderTarget* target)
{
	for (int index = 0; index <= 3; index++)
	{
		target->draw(rectangles[index]);
	}
}