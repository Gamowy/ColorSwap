#pragma once
#include "ColorSwap.h"
#include "Player.h"
#include "Item.h"

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
	Event event;
	GameState gameStatus;
	Player* player;

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
	void checkOutOfMapCondition();

public:
	Game();
	virtual ~Game();

	const bool running() const;
	void update();
	void render();
};


