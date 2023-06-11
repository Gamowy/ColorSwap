#pragma once
#include "ColorSwap.h"

using namespace sf;

//holds records of high scores from data.dat file
struct FileRecord {
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
	std::wstring newNickname;
	std::string newDate;

	//Private methods
	bool mouseOverButton(RenderWindow* window);

public:
	GameOverScreen(Font& font);
	virtual ~GameOverScreen();

	bool backToMenuPressed(RenderWindow* window);
	void setScores(std::wfstream& scoresile, unsigned int score);
	void update(RenderWindow* window);
	void render(RenderTarget* target);
};

