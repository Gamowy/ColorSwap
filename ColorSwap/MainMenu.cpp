#include "ColorSwap.h"
#include "MainMenu.h"

MainMenu::MainMenu(Font& font)
{
	currentPage = MenuPage::Main;
	Color colors[4] = { COLOR_SWAP_CYAN,COLOR_SWAP_PURPLE,COLOR_SWAP_RED,COLOR_SWAP_YELLOW };

	//set title font, size, color and position
	title[0].setFont(font);
	title[0].setCharacterSize(DEFAULT_FONT_SIZE * 3.f);
	title[0].setFillColor(Color::White);
	title[0].setString("COLOR");
	title[0].setPosition(WINDOW_WIDTH / 2.f - title[0].getLocalBounds().width / 2.f, 85.f);
	for (int index = 1; index < 5; index++)
	{
		title[index].setFont(font);
		title[index].setCharacterSize(DEFAULT_FONT_SIZE * 3.5f);
		title[index].setFillColor(colors[index - 1]);
	}
	title[1].setString("S");
	title[2].setString("W");
	title[3].setString("A");
	title[4].setString("P");
	title[1].setPosition(title[0].getGlobalBounds().left, 185.f);
	title[2].setPosition(title[1].getGlobalBounds().left + title[1].getGlobalBounds().width + 7.5f, 185.f);
	title[3].setPosition(title[2].getGlobalBounds().left + title[2].getGlobalBounds().width - 7.5f, 185.f);
	title[4].setPosition(title[0].getGlobalBounds().left + title[0].getGlobalBounds().width - title[4].getLocalBounds().width, 185.f);

	//set play button font, size, color and position
	play.buttonText.setFont(font);
	play.buttonText.setCharacterSize(DEFAULT_FONT_SIZE);
	play.buttonText.setFillColor(Color::White);
	play.buttonText.setString("PLAY");
	play.buttonText.setPosition(WINDOW_WIDTH / 2.f - play.buttonText.getLocalBounds().width / 2.f, WINDOW_HEIGHT / 2.f);

	//set title how to play button font, size, color and position
	howToPlay.buttonText.setFont(font);
	howToPlay.buttonText.setCharacterSize(DEFAULT_FONT_SIZE);
	howToPlay.buttonText.setFillColor(Color::White);
	howToPlay.buttonText.setString("HOW TO PLAY");
	howToPlay.buttonText.setPosition(WINDOW_WIDTH / 2.f - howToPlay.buttonText.getLocalBounds().width / 2.f, WINDOW_HEIGHT / 2.f + 50.f);

	//set scoreboard button font, size, color and position
	scoreboard.buttonText.setFont(font);
	scoreboard.buttonText.setCharacterSize(DEFAULT_FONT_SIZE);
	scoreboard.buttonText.setFillColor(Color::White);
	scoreboard.buttonText.setString("SCOREBOARD");
	scoreboard.buttonText.setPosition(WINDOW_WIDTH / 2.f - scoreboard.buttonText.getLocalBounds().width / 2.f, WINDOW_HEIGHT / 2.f + 100.f);

	//set exit button font, size, color and position
	exit.buttonText.setFont(font);
	exit.buttonText.setCharacterSize(DEFAULT_FONT_SIZE);
	exit.buttonText.setFillColor(Color::White);
	exit.buttonText.setString("EXIT");
	exit.buttonText.setPosition(WINDOW_WIDTH / 2.f - exit.buttonText.getLocalBounds().width / 2.f, WINDOW_HEIGHT / 2.f + 150.f);

	//set back button font, size, color and position
	back.buttonText.setFont(font);
	back.buttonText.setCharacterSize(DEFAULT_FONT_SIZE);
	back.buttonText.setFillColor(Color::White);
	back.buttonText.setString("BACK");
	back.buttonText.setPosition(WINDOW_WIDTH / 2.f - back.buttonText.getLocalBounds().width / 2.f, WINDOW_HEIGHT - 100.f);

	setHowToPlayMessage(font);
}

MainMenu::~MainMenu()
{
}

bool MainMenu::playButtonPressed(RenderWindow* window)
{
	if (currentPage == MenuPage::Main)
	{
		return play.isPressed(window);
	}
	return false;
}

void MainMenu::howToPlayButtonPressed(RenderWindow* window)
{
	if(currentPage==MenuPage::Main && howToPlay.isPressed(window))
	{
		currentPage = MenuPage::HowToPlay;
	}
}

void MainMenu::scoreboardButtonPressed(RenderWindow* window)
{
	if(currentPage == MenuPage::Main && scoreboard.isPressed(window))
	{
		currentPage = MenuPage::Scoreboard;
	}
}

bool MainMenu::exitButtonPressed(RenderWindow* window)
{
	if(currentPage == MenuPage::Main)
	{
		return exit.isPressed(window);
	}
	return false;
}

void MainMenu::backButtonPressed(RenderWindow* window)
{
	if ((currentPage == MenuPage::HowToPlay || currentPage == MenuPage::Scoreboard) && back.isPressed(window))
	{
		currentPage = MenuPage::Main;
	}
}

void MainMenu::setHowToPlayMessage(Font& font)
{
	std::string message;
	message.append("					 HOW TO PLAY\n\n");
	message.append("- You can jump using either the left\n  mouse button or spacebar\n");
	message.append("- The game ends when your ball\n  collides with an obstacle or falls\n  out of view\n");
	message.append("- You can safely pass through\n  barriers of the same color as your\n  ball\n");
	message.append("- Your goal is to collect as many\n  stars as you can. Good luck!\n");
	howToPlayMessage.setFont(font);
	howToPlayMessage.setCharacterSize(DEFAULT_FONT_SIZE);
	howToPlayMessage.setFillColor(Color::White);
	howToPlayMessage.setString(message);
	howToPlayMessage.setPosition(0, 100.f);
}

void MainMenu::render(RenderTarget* target)
{
	switch(currentPage)
	{
	case(Main):
		for (int index = 0; index < 5; index++)
		{
			target->draw(title[index]);
		}
		play.render(target);
		howToPlay.render(target);
		scoreboard.render(target);
		exit.render(target);
		break;
	case(HowToPlay):
		target->draw(howToPlayMessage);
		back.render(target);
		break;
	case(Scoreboard):
		back.render(target);
		break;
	}
}

void MainMenu::update(RenderWindow* window)
{

	switch(currentPage)
	{
	case(Main):
		play.update(window);
		howToPlay.update(window);
		scoreboard.update(window);
		exit.update(window);
		howToPlayButtonPressed(window);
		scoreboardButtonPressed(window);
		break;
	case(HowToPlay):
		back.update(window);
		backButtonPressed(window);
		break;
	case(Scoreboard):
		back.update(window);
		backButtonPressed(window);
		break;
	}

}
