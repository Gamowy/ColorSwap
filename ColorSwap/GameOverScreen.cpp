#include "ColorSwap.h"
#include "GameOverScreen.h"

GameOverScreen::GameOverScreen(Font& font)
{
	//Game Over Text
	gameOverText.setFont(font);
	gameOverText.setCharacterSize(64);
	gameOverText.setFillColor(COLOR_SWAP_RED);
	gameOverText.setStyle(Text::Bold);
	gameOverText.setPosition(125.f, 100.f);
	gameOverText.setString("Game Over");

	//Score Text
	scoreText.setFont(font);
	scoreText.setCharacterSize(DEFAULT_FONT_SIZE);
	scoreText.setFillColor(Color::White);
	scoreText.setPosition(100.f, 250.f);
	
	//High Score text
	highScoreText.setFont(font);
	highScoreText.setCharacterSize(DEFAULT_FONT_SIZE);
	highScoreText.setFillColor(Color::White);
	highScoreText.setPosition(100.f, 300.f);
	highScoreText.setFillColor(COLOR_SWAP_CYAN);
	
	//Back to menu text
	backToMenuText.setFont(font);
	backToMenuText.setCharacterSize(DEFAULT_FONT_SIZE);
	backToMenuText.setFillColor(Color::White);
	backToMenuText.setStyle(Text::Bold);
	backToMenuText.setPosition(125.f, 500.f);
;	backToMenuText.setString("-> BACK TO MENU <-");

	//Username
	wchar_t usernameBuffer[UNLEN+1];
	DWORD username_len = UNLEN + 1;
	GetUserName(usernameBuffer, &username_len);
	std::wstring username(usernameBuffer);
	newNickname = username;

	//Time
	auto timeBuffer = std::chrono::system_clock::now();
	time_t time = std::chrono::system_clock::to_time_t(timeBuffer);
	newDate = std::ctime(&time);
}

GameOverScreen::~GameOverScreen()
{
}

bool GameOverScreen::mouseOverButton(RenderWindow* window)
{
	if (Mouse::getPosition(*window).x >= backToMenuText.getPosition().x && Mouse::getPosition(*window).x <= backToMenuText.getPosition().x + backToMenuText.getLocalBounds().width &&
		Mouse::getPosition(*window).y >= backToMenuText.getPosition().y && Mouse::getPosition(*window).y <= backToMenuText.getPosition().y + backToMenuText.getLocalBounds().height + 10.f)
	{
		return true;
	}
	return false;
}

bool GameOverScreen::backToMenuPressed(RenderWindow* window)
{
	if (Keyboard::isKeyPressed(Keyboard::Enter) || (Mouse::isButtonPressed(Mouse::Left) && mouseOverButton(window)))
	{
		return true;
	}
	return false;
}

void GameOverScreen::setScores(std::wfstream& scoresFile, unsigned int score)
{
	fileRecord records[3];
	std::wstring scoreBuffer;
	std::wstring currentDate(newDate.begin(), newDate.end()-1);

	//read file
	scoresFile.open("Assets/data.dat");
	scoresFile.seekg(0);
	for (int i = 0; i < 3; i++)
	{
		//save score from file to buffer, decrypt it and save to record
		std::getline(scoresFile, scoreBuffer);
		scoreBuffer = crypt(scoreBuffer); 
		records[i].score = stoi(scoreBuffer);
		
		//save nickname and date from file
		std::getline(scoresFile, records[i].nickname);
		std::getline(scoresFile, records[i].date);
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

			//encrypt new record nickname and date
			records[i].score = score;
			records[i].nickname = crypt(newNickname);
			records[i].date = crypt(currentDate);
			break;
		}
	}

	//save new scores to file
	scoresFile.seekg(0);
	for (int i = 0; i < 3; i++)
	{
		//save score to file as encrypted wstring
		scoresFile << crypt(std::to_wstring(records[i].score)) << std::endl;
		//nickname and date are already encrypted
		scoresFile << records[i].nickname << std::endl; 
		scoresFile << records[i].date << std::endl; 
	}
	scoresFile.close();
	
	//set score text
	scoreText.setString("Score: " + std::to_string(score));

	//set high score text
	highScoreText.setString("High-Score: " + std::to_string(records[0].score));
}

void GameOverScreen::update(RenderWindow* window)
{
	if (mouseOverButton(window))
	{
		backToMenuText.setFillColor(COLOR_SWAP_YELLOW);
	}
	else
	{
		backToMenuText.setFillColor(Color::White);
	}
}

void GameOverScreen::render(RenderTarget* target)
{
	target->draw(gameOverText);
	target->draw(scoreText);
	target->draw(highScoreText);
	target->draw(backToMenuText);
}