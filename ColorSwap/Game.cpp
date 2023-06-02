#include "ColorSwap.h"
#include "Game.h"

void Game::initVariables()
{
	window = nullptr;
}

void Game::initWindow()
{
	videoMode.width = WINDOW_WIDTH;
	videoMode.height = WINDOW_HEIGHT;
	windowIcon.loadFromFile("Assets/Images/icon.png");
	window = new RenderWindow(VideoMode(this->videoMode), "Color Swap", Style::Titlebar | Style::Close);
	window->setIcon(this->windowIcon.getSize().x, this->windowIcon.getSize().y, this->windowIcon.getPixelsPtr());
	window->setFramerateLimit(FRAME_RATE);
}

void Game::pollEvents()
{
	while (window->pollEvent(event)) 
	{
		switch (event.type)
		{
		case Event::Closed:
			window->close();
			break;
		case Event::KeyPressed:
			if (event.key.code == Keyboard::Escape)
				window->close();
			break;
		}		
	}
}

Game::Game()
{
	initVariables();
	initWindow();
}

Game::~Game()
{
	delete window;
}

const bool Game::running() const
{
	return window->isOpen();
}

void Game::update()
{
	pollEvents();
}

void Game::render()
{
	window->clear(Color(44, 50, 66));
	//Render game here
	window->draw(tekst);

	window->display();
}
