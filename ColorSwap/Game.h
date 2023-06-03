#pragma once
#include "ColorSwap.h"
#include "Player.h"
#include "Obstacle.h"

using namespace sf;

enum GameState {Menu, Play, GameOver, Error};

class Game
{
private:
	//Window variables
	RenderWindow* window;
	VideoMode videoMode;
	View* view;

	//Game variables
	unsigned int points;
	Event event;
	GameState gameStatus;
	Player* player;
	std::vector<Obstacle*> obstacles;

	//Files to load
	Image windowIcon;
	Texture starTexture;
	Texture colorSwitchTexture;

	//Private methods
	void initVariables();
	void initWindow();
	void loadFiles();
	void pollEvents();
	void moveView();
	void checkColisions();
	void createObstacles();
	void removeObstacles();
	void checkOutOfMapCondition();
	void renderObstacles();

public:
	Game();
	virtual ~Game();

	const bool running() const;
	void update();
	void render();
};


