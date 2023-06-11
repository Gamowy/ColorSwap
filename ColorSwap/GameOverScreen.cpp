#include "ColorSwap.h"
#include "GameOverScreen.h"

GameOverScreen::GameOverScreen(Font& font)
{
	//game Over Text
	gameOverText.setFont(font);
	gameOverText.setCharacterSize(64);
	gameOverText.setFillColor(COLOR_SWAP_RED);
	gameOverText.setStyle(Text::Bold);
	gameOverText.setPosition(125.f, 100.f);
	gameOverText.setString("Game Over");

	//score Text
	scoreText.setFont(font);
	scoreText.setCharacterSize(DEFAULT_FONT_SIZE);
	scoreText.setFillColor(Color::White);
	scoreText.setPosition(100.f, 250.f);
	
	//high Score text
	highScoreText.setFont(font);
	highScoreText.setCharacterSize(DEFAULT_FONT_SIZE);
	highScoreText.setFillColor(Color::White);
	highScoreText.setPosition(100.f, 300.f);
	highScoreText.setFillColor(COLOR_SWAP_CYAN);
	
	//back to menu button
	backToMenu.buttonText.setFont(font);
	backToMenu.buttonText.setCharacterSize(DEFAULT_FONT_SIZE);
	backToMenu.buttonText.setFillColor(Color::White);
	backToMenu.buttonText.setStyle(Text::Bold);
	backToMenu.buttonText.setPosition(125.f, 500.f);
	backToMenu.buttonText.setString("--> BACK TO MENU <--");

	//username variable
	wchar_t usernameBuffer[UNLEN+1];
	DWORD username_len = UNLEN + 1;
	GetUserName(usernameBuffer, &username_len);
	std::wstring username(usernameBuffer);
	newNickname = username;
}

GameOverScreen::~GameOverScreen()
{
}

bool GameOverScreen::backToMenuPressed(RenderWindow* window)
{
	if (backToMenu.isPressed(window))
	{
		return true;
	}
	else
	{
		return false;
	}
}

void GameOverScreen::setScores(ScoresFile& file, unsigned int score)
{
	//date variable
	auto timeBuffer = std::chrono::system_clock::now();
	time_t time = std::chrono::system_clock::to_time_t(timeBuffer);
	newDate = std::ctime(&time);

	FileRecord records[3];
	std::wstring currentDate(newDate.begin(), newDate.end() - 1);

	//read records from file
	for (int i = 0; i < 3; i++)
	{
		records[i] = file.readRecord(i);
	}

	//save current score to records if higher then one of previous scores 
	for (int i = 0; i < 3; i++)
	{
		if (score > records[i].score)
		{
			if (i == 0)
			{
				std::swap(records[1], records[2]);
				std::swap(records[0], records[1]);
			}
			else if (i == 1)
			{
				std::swap(records[1], records[2]);
			}

			records[i].score = score;
			records[i].nickname = newNickname;
			records[i].date = currentDate;
			break;
		}
	}

	//save new scores to file
	file.save(records);
	
	//set score text
	scoreText.setString("Score: " + std::to_string(score));

	//set high score text
	highScoreText.setString("High-Score: " + std::to_string(records[0].score));
}

void GameOverScreen::update(RenderWindow* window)
{
	if (backToMenu.mouseOverButton(window))
	{
		backToMenu.buttonText.setFillColor(COLOR_SWAP_YELLOW);
	}
	else
	{
		backToMenu.buttonText.setFillColor(Color::White);
	}
}

void GameOverScreen::render(RenderTarget* target)
{
	target->draw(gameOverText);
	target->draw(scoreText);
	target->draw(highScoreText);
	backToMenu.render(target);
}