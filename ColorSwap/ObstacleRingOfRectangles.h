#pragma once
#include"ColorSwap.h"
#include "Obstacle.h"

//Integer distribution for ring variation
static std::uniform_int_distribution<int> obstacleRingVariation(0, 1);

class ObstacleRingOfRectangles : virtual public Obstacle
{
private:
    int ringVariation;
    Vector2f center;
    RectangleShape* rectangles;
    float rotationSpeed;
public:
    ObstacleRingOfRectangles(float yPosition, Texture& starTexture, Texture& colorSwitchTexture);
    virtual ~ObstacleRingOfRectangles();

    bool checkObstacleColision(RectangleShape player, Color playerColor);
    void update();
    void renderObstacle(RenderTarget* target);
};