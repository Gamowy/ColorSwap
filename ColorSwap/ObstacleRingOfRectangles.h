#pragma once
#include"ColorSwap.h"
#include "Obstacle.h"
class ObstacleRingOfRectangles :
    virtual public Obstacle
{
    Vector2f center;
    RectangleShape rectangles[12];
    float rotationSpeed;
public:
    ObstacleRingOfRectangles(float yPosition, Texture& starTexture, Texture& colorSwitchTexture);
    virtual ~ObstacleRingOfRectangles();
    bool checkObstacleColision(RectangleShape player, Color playerColor);
    void update();
    void renderObstacle(RenderTarget* target);
};

