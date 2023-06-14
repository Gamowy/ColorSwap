#pragma once
#include"ColorSwap.h"
#include "Obstacle.h"

class ObstacleLine : public Obstacle
{
private:
    Vector2f center;
    RectangleShape rectangles[10];
    Vector2f rectangleSpeed;
public:
    ObstacleLine(float yPosition, Texture& starTexture, Texture& colorSwitchTexture);
    virtual ~ObstacleLine();

    bool checkObstacleColision(RectangleShape player, Color playerColor);
    void update();
    void renderObstacle(RenderTarget* target);
};