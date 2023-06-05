#include "ColorSwap.h"
#include "Game.h"

void Game::initVariables()
{
	gameStatus = GameState::Menu;
	window = nullptr;
	player = new Player();
	view = new View();
	points = 0;
	starTexture.setSmooth(true);
	colorSwitchTexture.setSmooth(true);
	obstacles.push_back(new Obstacle(99500.f, starTexture, colorSwitchTexture));
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

	pointCounter = new PointCounter(font);
}

void Game::initErrorWindow()
{
	sf::RenderWindow window(sf::VideoMode(300, 0), "File loading error");
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		window.clear();
		window.display();
	}
}

void Game::loadFiles()
{
	try {
		if (!(
			windowIcon.loadFromFile("Assets/Images/icon.png") &&
			starTexture.loadFromFile("Assets/Images/star.png") &&
			colorSwitchTexture.loadFromFile("Assets/Images/colorswitch.png") &&
			font.loadFromFile("Assets/Fonts/Exo-Regular.ttf")
			))
			throw (std::runtime_error("File loading error"));

	}
	catch (std::runtime_error)
	{
		initErrorWindow();
		exit(0);
	}
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
	for (int i = 0; i < obstacles.size(); i++) 
	{
		if (obstacles.at(i)->checkObstacleColision(player->getBounds()))
		{
			std::cout << "Game over\n";
			gameStatus = GameState::GameOver;
		}

		if (obstacles.at(i)->checkStarColision(player->getBounds()))
		{
			points++;
			std::cout << "Star!\n";
		}

		if (obstacles.at(i)->checkSwitchColision(player->getBounds()))
		{
			std::cout << "Switch!\n";
		}
	}
}

void Game::createObstacles()
{
	//Tutaj bedziemy automatycznie tworzyc przeszkody kiedy widok bedzie sie przesuwal
	//To zrobimy dopiero jak beda juz stworzone wszystkie rodzaje przeszkod
	//Narazie przeszkody dodajemy recznie w metodzie initVariables();
}


void Game::removeObstacles()
{
	//remove obstacles that are out of view
	for (int i = 0; i < obstacles.size(); i++) 
	{
		if (obstacles.at(i)->getYPosition() > view->getCenter().y + 0.6f * WINDOW_HEIGHT)
		{
			obstacles.erase(obstacles.begin() + i);
		}
	}
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
	delete pointCounter;
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
			pointCounter->update(view->getCenter(), points);
			checkColisions();
			checkOutOfMapCondition();
			createObstacles();
			removeObstacles();
			break;
	}
}

void Game::renderObstacles()
{
	for (int i = 0; i < obstacles.size(); i++)
	{
		obstacles.at(i)->render(window);
	}
}
  
void Game::render()
{
	window->clear(Color(44, 50, 66));
	//Render game here
	window->setView(*view);
	player->render(window);
	pointCounter->render(window);
	renderObstacles();

	window->display();
}
