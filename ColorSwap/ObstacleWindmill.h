#pragma once
#include "Obstacle.h"
class ObstacleWindmill : virtual public Obstacle
{
    RectangleShape rectangles[4];
public:
    ObstacleWindmill(float yPosition, Texture& starTexture, Texture& colorSwitchTexture);
    virtual ~ObstacleWindmill();
    bool checkObstacleColision(RectangleShape player, Color playerColor);
    void update();
    void renderObstacle(RenderTarget* target);
};

