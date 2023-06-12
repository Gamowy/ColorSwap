#include "ColorSwap.h"
#include "ObstacleCrusher.h"
ObstacleCrusher::ObstacleCrusher(float yPosition, Texture& starTexture, Texture& colorSwitchTexture) : Obstacle(yPosition, starTexture, colorSwitchTexture)
{
	Color colors[4] = { COLOR_SWAP_CYAN, COLOR_SWAP_PURPLE, COLOR_SWAP_RED, COLOR_SWAP_YELLOW };
	center.x = WINDOW_WIDTH / 2.f;
	center.y = yPosition;

	star->movePosition(-18.f);
	colorSwitch->movePosition(-90.f);

	for (int index = 0; index <= 3; index++)
	{
		rectangles[index].setFillColor(colors[index]);
		rectangles[index].setSize(Vector2f(20.f, 70.f));
		if (index== 0 || index == 3)
		rectangles[index].setPosition(center.x - 12, center.y - 140 + 70 * index);
		else
		rectangles[index].setPosition(center.x + 148, center.y - 140 + 70 * index);
	}
	for (int index = 4; index <= 7; index++)
	{
		rectangles[index].setFillColor(colors[index - 4]);
		rectangles[index].setSize(Vector2f(20.f, 70.f));
		if (index == 4 || index == 7)
		rectangles[index].setPosition(center.x - 32, center.y - 140 + 70 * (index - 4));
		else
		rectangles[index].setPosition(center.x - 192, center.y - 140 + 70 * (index - 4));
	}
}

ObstacleCrusher::~ObstacleCrusher()
{
}

bool ObstacleCrusher::checkObstacleColision(RectangleShape player, Color playerColor)
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

void ObstacleCrusher::update()
{
	
	for (int index = 0; index <= 3; index+=3)
	{
		if (rectangles[index].getPosition().x == center.x - 12.f)
			rectangleSpeed[0].x = 4.f;
		if (rectangles[index].getPosition().x == center.x + 148.f)
			rectangleSpeed[0].x = -4.f;
		rectangles[index].move(rectangleSpeed[0]);
	}
	for (int index = 1; index <= 2; index++)
	{
		if (rectangles[index].getPosition().x == center.x + 148.f)
			rectangleSpeed[1].x = -4.f;
		if (rectangles[index].getPosition().x == center.x - 12.f)
			rectangleSpeed[1].x = 4.f;
		rectangles[index].move(rectangleSpeed[1]);
	}
	for (int index = 4; index <= 7; index += 3)
	{
		if (rectangles[index].getPosition().x == center.x - 32.f)
			rectangleSpeed[2].x = -4.f;
		if (rectangles[index].getPosition().x == center.x - 192.f)
			rectangleSpeed[2].x = 4.f;
		rectangles[index].move(rectangleSpeed[2]);
	}
	for (int index = 5; index <= 6; index++)
	{
		if (rectangles[index].getPosition().x == center.x - 192.f)
			rectangleSpeed[3].x = 4.f;
		if (rectangles[index].getPosition().x == center.x - 32.f)
			rectangleSpeed[3].x = -4.f;
		rectangles[index].move(rectangleSpeed[3]);
	}

}

void ObstacleCrusher::renderObstacle(RenderTarget* target)
{
	for (int index = 0; index <= 7; index++)
	{
		target->draw(rectangles[index]);
	}
}