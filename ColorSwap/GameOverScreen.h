#pragma once
#include "ColorSwap.h"

using namespace sf;

class GameOverScreen
{
private:
	Text gameOverText;
	Text scoreText;
	Text highScoreText;
	Text backToMenuText;

	//Private methods
	bool mouseOverButton(RenderWindow* window);
	

public:
	GameOverScreen(Font& font);
	virtual ~GameOverScreen();

	bool backToMenuPressed(RenderWindow* window);
	void setScores(unsigned int score, unsigned int highScore = 0);
	void update(RenderWindow* window);
	void render(RenderTarget* target);
};

