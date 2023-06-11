#pragma once
#include "ColorSwap.h"
#include "Button.h"
#include "ScoresFile.h"

using namespace sf;

class GameOverScreen
{
private:
	Text gameOverText;
	Text scoreText;
	Text highScoreText;
	Button backToMenu;
	std::wstring newNickname;
	std::string newDate;

public:
	GameOverScreen(Font& font, SoundBuffer& hoverSoundFil);
	virtual ~GameOverScreen();

	bool backToMenuPressed(RenderWindow* window);
	void setScores(ScoresFile& scoresile, unsigned int score);
	void update(RenderWindow* window);
	void render(RenderTarget* target);
};

