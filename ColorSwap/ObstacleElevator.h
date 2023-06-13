#pragma once
#include"ColorSwap.h"
#include "Obstacle.h"
class ObstacleElevator : virtual public Obstacle
{
private:
    Vector2f center;
    RectangleShape rectangles[11];
    Vector2f rectangleSpeed[3];

public:
    ObstacleElevator(float yPosition, Texture& starTexture, Texture& colorSwitchTexture);
    virtual ~ObstacleElevator();
    bool checkObstacleColision(RectangleShape player, Color playerColor);
    void update();
    void renderObstacle(RenderTarget* target);
};
