#include "ColorSwap.h"
#include "Game.h"

void Game::initVariables()
{
	gameStatus = GameState::Menu;
	window = nullptr;
	player = new Player();
	view = new View();
	points.push_back(Item(Vector2f(200.f, 200.f)));
}

void Game::initWindow()
{
	videoMode.width = WINDOW_WIDTH;
	videoMode.height = WINDOW_HEIGHT;
	windowIcon.loadFromFile("Assets/Images/icon.png");
	window = new RenderWindow(VideoMode(this->videoMode), "Color Swap", Style::Titlebar | Style::Close);
	window->setIcon(this->windowIcon.getSize().x, this->windowIcon.getSize().y, this->windowIcon.getPixelsPtr());
	window->setFramerateLimit(FRAME_RATE);
	view->setCenter(player->getPlayerPosition().x, player->getPlayerPosition().y - 0.3f * WINDOW_HEIGHT);
	view->setSize(WINDOW_WIDTH, WINDOW_HEIGHT);
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
			if (gameStatus == GameState::Menu && event.key.code == Keyboard::Space)
				gameStatus = GameState::Play;
			break;
		}		
	}
}

void Game::moveView()
{
	if (player->getPlayerPosition().y <= view->getCenter().y + 0.3f * WINDOW_HEIGHT)
	{
		view->move(player->getPlayerSpeed());
	}
}

void Game::checkFallCondition()
{
	if (player->getPlayerPosition().y > view->getCenter().y + 0.6f * WINDOW_HEIGHT)
	{
		std::cout << "Game over\n";
		gameStatus = GameState::GameOver;
	}
}

void Game::renderPoints(RenderTarget* target)
{
	for (int i = 0; i < points.size(); i++)
	{
		points.at(i).render(target);
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
	delete player;
	delete view;
}

const bool Game::running() const
{
	return window->isOpen();
}

void Game::update()
{
	pollEvents();
	switch (gameStatus) {
		case GameState::Play:
			player->update();
			moveView();
			checkFallCondition();
			break;
	}

	
}

void Game::render()
{
	window->clear(Color(44, 50, 66));
	//Render game here
	window->setView(*view);
	player->render(window);
	renderPoints(window);

	window->display();
}
