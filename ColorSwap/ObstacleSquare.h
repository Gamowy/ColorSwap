#pragma once
#include "ColorSwap.h"
#include "Obstacle.h"

class ObstacleSquare : virtual public Obstacle
{
    Vector2f center;
    RectangleShape rectangles[4];
    float rotationSpeed;
public:
    ObstacleSquare(float yPosition, Texture& starTexture, Texture& colorSwitchTexture);
    virtual ~ObstacleSquare();
    bool checkObstacleColision(RectangleShape player, Color playerColor);
    void update();
    void renderObstacle(RenderTarget* target);
};