#include "ColorSwap.h"
#include "ObstacleElevator.h"
ObstacleElevator::ObstacleElevator(float yPosition, Texture& starTexture, Texture& colorSwitchTexture) : Obstacle(yPosition, starTexture, colorSwitchTexture)
{
	Color colors[4] = { COLOR_SWAP_CYAN, COLOR_SWAP_PURPLE, COLOR_SWAP_RED, COLOR_SWAP_YELLOW };
	center.x = WINDOW_WIDTH / 2.f;
	center.y = yPosition;
	rectangleSpeed[0].x = 0;									//setting 3 different speeds needed by the elevator	
	rectangleSpeed[0].y = -2;
	rectangleSpeed[1].x = 2;
	rectangleSpeed[1].y = 0;
	rectangleSpeed[2].x = -2;
	rectangleSpeed[2].y = 0;
	star->movePosition(-18.f);
	colorSwitch->movePosition(-100.f);

	for (int index = 0; index <= 3; index++)					//placing rectangles in the middle
	{
		rectangles[index].setFillColor(colors[index]);
		rectangles[index].setSize(Vector2f(20.f, 80.f));
		rectangles[index].rotate(90.f);
		rectangles[index].setPosition(center.x + 30, center.y - 140 + 90 * index);
		
	}
	for (int index = 4; index <= 7; index++)					//placing rectangles at the bottom
	{
		rectangles[index].setFillColor(colors[index - 4]);
		rectangles[index].setSize(Vector2f(20.f, 80.f));
		rectangles[index].rotate(90.f);
		rectangles[index].setPosition(center.x + 120 + 90 * (index - 4), center.y + 130.f);
		
			
	}
	for (int index = 8; index <= 10; index++)					//placing rectangles on top
	{
		rectangles[index].setFillColor(colors[index-(5+((index-8)*2))]);
		rectangles[index].setSize(Vector2f(20.f, 80.f));
		rectangles[index].rotate(90.f);
		rectangles[index].setPosition(center.x + 120 + 90 * (index - 8), center.y - 140.f);
	}
}

ObstacleElevator::~ObstacleElevator()
{
}

bool ObstacleElevator::checkObstacleColision(RectangleShape player, Color playerColor)
{
	for (int index = 0; index <= 10; index++)
	{
		if (collision::areColliding(rectangles[index], player) && playerColor != rectangles[index].getFillColor())
		{
			return true;
		}
	}
	return false;
}

void ObstacleElevator::update()
{
	for (int index = 0; index <= 10; index++)					//teleports rectangles to a new location
	{
		if (rectangles[index].getPosition().x == center.x + 390 && rectangles[index].getPosition().y == center.y - 140)
			rectangles[index].setPosition(center.x + 390, center.y + 130.f);
	}
	for (int index = 0; index <= 10; index++)					//moves the rectangles to the left
	{
		if (rectangles[index].getPosition().y == center.y + 130 && rectangles[index].getPosition().x > center.x + 30 && rectangles[index].getPosition().x <= center.x + 390)
			rectangles[index].move(rectangleSpeed[2]);
	}
	for (int index = 0; index <= 10; index++)					//moves the rectangles upwards
	{
		if (rectangles[index].getPosition().x == center.x + 30 && rectangles[index].getPosition().y > center.y + -140 && rectangles[index].getPosition().y <= center.y + 130)
			rectangles[index].move(rectangleSpeed[0]);
	}
	for (int index = 0; index <= 10; index++)					//moves the rectangles to the right
	{
		if (rectangles[index].getPosition().y == center.y - 140 && rectangles[index].getPosition().x >= center.x + 30 && rectangles[index].getPosition().x <= center.x + 390)
			rectangles[index].move(rectangleSpeed[1]);
	}



}

void ObstacleElevator::renderObstacle(RenderTarget* target)
{
	for (int index = 0; index <= 10; index++)
	{
		target->draw(rectangles[index]);
	}
}