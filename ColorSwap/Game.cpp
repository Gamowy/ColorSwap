#include "ColorSwap.h"
#include "Game.h"

void Game::initVariables()
{
	gameStatus = GameState::Menu;
	window = nullptr;
	player = new Player();
	view = new View();
	starTexture.setSmooth(true);
	colorSwitchTexture.setSmooth(true);
	testObstacle = new Obstacle(99700.f, starTexture, colorSwitchTexture);
}

void Game::initWindow()
{
	//Create window
	videoMode.width = WINDOW_WIDTH;
	videoMode.height = WINDOW_HEIGHT;
	window = new RenderWindow(VideoMode(this->videoMode), "Color Swap", Style::Titlebar | Style::Close);
	window->setIcon(this->windowIcon.getSize().x, this->windowIcon.getSize().y, this->windowIcon.getPixelsPtr());
	window->setFramerateLimit(FRAME_RATE);
	
	//Create a view and center it on player
	view->setCenter(player->getPosition().x, player->getPosition().y - 0.3f * WINDOW_HEIGHT);
	view->setSize(WINDOW_WIDTH, WINDOW_HEIGHT);
}

void Game::loadFiles()
{
	windowIcon.loadFromFile("Assets/Images/icon.png");
	starTexture.loadFromFile("Assets/Images/star.png");
	colorSwitchTexture.loadFromFile("Assets/Images/colorswitch.png");
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
	//Move view up when player moves up
	if (player->getPosition().y <= view->getCenter().y + 0.1f * WINDOW_HEIGHT)
	{
		view->move(player->getSpeed());
	}
}

void Game::checkColisions()
{
	testObstacle->checkColisions(player->getBounds());
}

void Game::checkOutOfMapCondition()
{
	//Check if player is out of bounds
	if (player->getPosition().y > view->getCenter().y + 0.6f * WINDOW_HEIGHT || (player->getPosition().y < -100000.f))
	{
		std::cout << "Game over\n";
		gameStatus = GameState::GameOver;
	}
}

Game::Game()
{
	loadFiles();
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
			checkColisions();
			checkOutOfMapCondition();
			break;
	}
}

void Game::render()
{
	window->clear(Color(44, 50, 66));
	//Render game here
	window->setView(*view);
	player->render(window);
	testObstacle->render(window);

	window->display();
}
