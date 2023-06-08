#pragma once
#include "Obstacle.h"

static std::uniform_int_distribution<int> sidePicker(0, 1);

class ObstacleWindmill : virtual public Obstacle
{
    RectangleShape rectangles[4];
    float rotationSpeed;
public:
    ObstacleWindmill(float yPosition, Texture& starTexture, Texture& colorSwitchTexture);
    virtual ~ObstacleWindmill();
    bool checkObstacleColision(RectangleShape player, Color playerColor);
    void update();
    void renderObstacle(RenderTarget* target);
};

