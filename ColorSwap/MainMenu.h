#pragma once
#include "ColorSwap.h"
#include "Button.h"

using namespace sf;

enum MenuPage { Main, HowToPlay, Scoreboard };

class MainMenu
{
	MenuPage currentPage;
	Text title[5];
	Text howToPlayMessage;
	Button play;
	Button howToPlay;
	Button scoreboard;
	Button exit;
	Button back;
public:
	MainMenu(Font &font);
	virtual ~MainMenu();
	bool playButtonPressed(RenderWindow* window);
	void howToPlayButtonPressed(RenderWindow* window);
	void scoreboardButtonPressed(RenderWindow* window);
	bool exitButtonPressed(RenderWindow* window);
	void backButtonPressed(RenderWindow* window);
	void setHowToPlayMessage(Font& font);
	void render(RenderTarget* target);
	void update(RenderWindow* window);
};

