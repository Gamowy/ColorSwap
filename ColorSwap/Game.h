#pragma once
#include "ColorSwap.h"

using namespace sf;

class Game
{
private:
	//Window variables
	RenderWindow* window;
	VideoMode videoMode;
	Image windowIcon;

	//Game variables
	Event event;

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


