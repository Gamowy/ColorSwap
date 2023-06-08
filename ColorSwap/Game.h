#pragma once
#include "ColorSwap.h"
#include "Player.h"
#include "Obstacle.h"
#include "ObstacleWindmill.h"
#include"ObstacleRingOfRectangles.h"
#include "PointCounter.h"

using namespace sf;

enum GameState {Menu, Play, GameOver, Error};
static std::uniform_int_distribution<int> obstacleRandomPick(0, 1);

class Game
{
private:
	//Window variables
	RenderWindow* window;
	VideoMode videoMode;
	View* view;
	PointCounter* pointCounter;

	//Game variables
	unsigned int score;
	Event event;
	GameState gameStatus;
	Player* player;
	std::vector<Obstacle*> obstacles;

	//Files to load
	Image windowIcon;
	Texture starTexture;
	Texture colorSwitchTexture;
	Font font;

	//Private methods
	void initVariables();
	void initWindow();
	void initErrorWindow(std::exception e);
	void loadFiles();
	void pollEvents();
	void moveView();
	void checkColisions();
	void obstacleGenerator();
	void createObstacle(float yPosition);
	void obstacleRemover();
	void checkOutOfMapCondition();
	void renderObstacles();
	void updateObstacles();

public:
	Game();
	virtual ~Game();

	const bool running() const;
	void update();
	void render();
};


