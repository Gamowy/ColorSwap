#pragma once
#include "ColorSwap.h"

using namespace sf;

struct fileRecord {
	int score = 0;
	std::wstring nickname;
	std::wstring date;
};

class GameOverScreen
{
private:
	Text gameOverText;
	Text scoreText;
	Text highScoreText;
	Text backToMenuText;
	std::wstring nickname;
	std::string scoreDate;

	//Private methods
	bool mouseOverButton(RenderWindow* window);

public:
	GameOverScreen(Font& font);
	virtual ~GameOverScreen();

	std::wstring crypt(std::wstring str);
	bool backToMenuPressed(RenderWindow* window);
	void setScores(std::wfstream& scoresile, unsigned int score);
	void update(RenderWindow* window);
	void render(RenderTarget* target);
};

