#pragma once
#include "ColorSwap.h"
#include "Obstacle.h"

//Integer distribution for windmill variation
static std::uniform_int_distribution<int> variation(0, 2);

class ObstacleWindmill : public Obstacle
{
private:
    int rectCount;
    RectangleShape* rectangles;
    float rotationSpeed;
public:
    ObstacleWindmill(float yPosition, Texture& starTexture, Texture& colorSwitchTexture);
    virtual ~ObstacleWindmill();

    bool checkObstacleColision(RectangleShape player, Color playerColor);
    void update();
    void renderObstacle(RenderTarget* target);
};