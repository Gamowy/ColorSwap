#pragma once
#include"ColorSwap.h"
#include "Obstacle.h"
class ObstacleCrusher : virtual public Obstacle
{
private:
    Vector2f center;
    RectangleShape rectangles[8];
    Vector2f rectangleSpeed[4];

public:
    ObstacleCrusher(float yPosition, Texture& starTexture, Texture& colorSwitchTexture);
    virtual ~ObstacleCrusher();
    bool checkObstacleColision(RectangleShape player, Color playerColor);
    void update();
    void renderObstacle(RenderTarget* target);
};
