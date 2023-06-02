#pragma once
#include "ColorSwap.h"
#include "Player.h"

using namespace sf;

enum GameState {Menu, Play, GameOver, Error};

class Game
{
private:
	//Window variables
	RenderWindow* window;
	VideoMode videoMode;
	Image windowIcon;
	View* view;

	//Game variables
	Event event;
	GameState gameStatus;
	Player* player;

	//Private methods
	void initVariables();
	void initWindow();
	void pollEvents();

public:
	Game();
	virtual ~Game();

	const bool running() const;
	void update();
	void render();
};


