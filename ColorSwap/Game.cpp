#include "ColorSwap.h"
#include "Game.h"

void Game::initVariables()
{
	gameStatus = GameState::Menu;
	window = nullptr;
	player = new Player();
	view = new View();
	score = 0;
	starTexture.setSmooth(true);
	colorSwitchTexture.setSmooth(true);
  
	//Create a view and center it on player
	view->setCenter(player->getPosition().x, player->getPosition().y - 0.3f * WINDOW_HEIGHT);
	view->setSize(WINDOW_WIDTH, WINDOW_HEIGHT);

	//create first obstacle
	obstacleGenerator();
}

void Game::initWindow()
{
	//Create window
	videoMode.width = WINDOW_WIDTH;
	videoMode.height = WINDOW_HEIGHT;
	window = new RenderWindow(VideoMode(this->videoMode), "Color Swap", Style::Titlebar | Style::Close);
	window->setIcon(this->windowIcon.getSize().x, this->windowIcon.getSize().y, this->windowIcon.getPixelsPtr());
	window->setFramerateLimit(FRAME_RATE);
	pointCounter = new PointCounter(font);
}

void Game::initErrorWindow(std::exception e)
{
	//Create error window
	sf::RenderWindow window(sf::VideoMode(300, 0), e.what());
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
	//Check if all the files loaded correctly
	try {
		if (!(
			windowIcon.loadFromFile("Assets/Images/icon.png") &&
			starTexture.loadFromFile("Assets/Images/star.png") &&
			colorSwitchTexture.loadFromFile("Assets/Images/colorswitch.png") &&
			font.loadFromFile("Assets/Fonts/Exo-Regular.ttf")
			))
			throw (std::runtime_error("File loading error"));

	}
	catch (std::runtime_error e)
	{
		initErrorWindow(e);
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
		if (obstacles.at(i)->checkObstacleColision(player->getHitbox(), player->getColor()) )
		{
			std::cout << "Game over\n";
			gameStatus = GameState::GameOver;
		}

		if (obstacles.at(i)->checkStarColision(player->getBounds()))
		{
			score++;
		}

		if (obstacles.at(i)->checkSwitchColision(player->getBounds()))
		{
			player->switchColor();
		}
	}
}

void Game::obstacleGenerator()
{
	if (obstacles.empty())
	{
		createObstacle(view->getCenter().y - 200.f);
	}
	else if (obstacles.back()->getYPosition() > view->getCenter().y - 0.8f * WINDOW_HEIGHT)
	{
		createObstacle(obstacles.back()->getYPosition() - 450.f);
	}

}

void Game::createObstacle(float yPosition)
{
	//create random obstacle when view moves
	int obstacleIndex = obstacleRandomPick(gen);
	switch (obstacleIndex) 
	{
		//windmill
		case 0:
			obstacles.push_back(new ObstacleWindmill(yPosition, starTexture, colorSwitchTexture));
			break;
	}
}

void Game::obstacleRemover()
{
	//remove obstacles that are out of view
	if (!obstacles.empty() && obstacles.front()->getYPosition() > view->getCenter().y + 0.8f * WINDOW_HEIGHT)
	{
		obstacles.erase(obstacles.begin());
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
			pointCounter->update(view->getCenter(), score);	
			obstacleGenerator();
			updateObstacles();
			checkColisions();
			checkOutOfMapCondition();
			obstacleRemover();		
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

void Game::updateObstacles()
{
	for (int i = 0; i < obstacles.size(); i++)
	{
		obstacles.at(i)->update();
	}
}
  
void Game::render()
{
	window->clear(Color(44, 50, 66));
	//Render game here
	window->setView(*view);
	player->render(window);
	renderObstacles();
	pointCounter->render(window);

	window->display();
}
