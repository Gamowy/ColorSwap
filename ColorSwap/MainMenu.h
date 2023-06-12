#pragma once
#include "ColorSwap.h"
#include "Button.h"
#include "ScoresFile.h"

using namespace sf;

enum MenuPage { Main, HowToPlay, Scoreboard };

class MainMenu
{
private:
	MenuPage currentPage;
	Text title[5];
	Text howToPlayMessage;
	Text scoreboardMessage;
	Button play;
	Button howToPlay;
	Button scoreboard;
	Button exit;
	Button back;
	ScoresFile leaderboard;
	FileRecord records[3];

public:
	MainMenu(Font &font, SoundBuffer& hoverSoundFile);
	virtual ~MainMenu();

	bool playButtonPressed(RenderWindow* window);
	void howToPlayButtonPressed(RenderWindow* window);
	void scoreboardButtonPressed(RenderWindow* window);
	bool exitButtonPressed(RenderWindow* window);
	void backButtonPressed(RenderWindow* window);
	void setHowToPlayMessage(Font& font);
	void getScores();
	void setScoreboardMessage();
	void render(RenderTarget* target);
	void update(RenderWindow* window);
};