#include "ColorSwap.h"
#include "Game.h"

void Game::initVariables()
{
	gameStatus = GameState::Menu;
	window = nullptr;
	gameOverScreen = nullptr;
	player = nullptr;
	view = nullptr;
	
	starTexture.setSmooth(true);
	colorSwitchTexture.setSmooth(true);
	getPointSound.setBuffer(getPointSoundFile);
	gameOverSound.setBuffer(gameOverSoundFile);
	gameOverSound.setVolume(25.f);
	backgroundMusic.setLoop(true);
	backgroundMusic.setVolume(25.f);
}

void Game::initWindow()
{
	//create window
	videoMode.width = WINDOW_WIDTH;
	videoMode.height = WINDOW_HEIGHT;
	window = new RenderWindow(VideoMode(this->videoMode), "Color Swap", Style::Titlebar | Style::Close);
	window->setIcon(this->windowIcon.getSize().x, this->windowIcon.getSize().y, this->windowIcon.getPixelsPtr());
	window->setFramerateLimit(FRAME_RATE);
	pointCounter = new PointCounter(font);

	//create view
	view = new View();
	view->setSize(WINDOW_WIDTH, WINDOW_HEIGHT);

	//crate game over screen
	gameOverScreen = new GameOverScreen(font);
}

void Game::initNewGame()
{
	player = new Player(jumpSoundFile);
	score = 0;

	//center view on player
	view->setCenter(player->getPosition().x, player->getPosition().y - 0.3f * WINDOW_HEIGHT);
	
	//create first obstacle
	obstacleGenerator();

	backgroundMusic.play();
	gameStatus = GameState::Play;
}

void Game::gameOver()
{
	backgroundMusic.stop();
	gameOverSound.play();
	sf::sleep(milliseconds(2000));
	
	delete player;
	player = nullptr;
	
	view->setCenter(WINDOW_WIDTH / 2.f, WINDOW_HEIGHT / 2.f);

	//clear obstacle container
	for (int i = 0; i < obstacles.size(); i++)
	{
		delete obstacles.at(i);
	}
	obstacles.clear();
	obstacles.shrink_to_fit();


	gameOverScreen->setScores(score);
	gameStatus = GameState::GameOver;
}

void Game::initErrorWindow(std::exception e)
{
	//create error window (windows specific)
	std::string string = e.what();
	std::wstring wstring(string.begin(), string.end());
	LPCWSTR errorMessage = wstring.c_str();
	MessageBox(NULL, errorMessage, L"An error has occured!", MB_ICONERROR | MB_OK);
}

void Game::loadFiles()
{
	std::ostringstream output;
	sf::err().rdbuf(output.rdbuf());

	//check if files loaded correctly
	try {
		if (!(
			windowIcon.loadFromFile("Assets/Images/icon.png") &&
			starTexture.loadFromFile("Assets/Images/star.png") &&
			colorSwitchTexture.loadFromFile("Assets/Images/colorswitch.png") &&
			font.loadFromFile("Assets/Fonts/Exo-Regular.ttf") &&
			jumpSoundFile.loadFromFile("Assets/Sounds/jump.ogg")&&
			getPointSoundFile.loadFromFile("Assets/Sounds/getPoint.ogg")&&
			gameOverSoundFile.loadFromFile("Assets/Sounds/gameOver.ogg") &&
			backgroundMusic.openFromFile("Assets/Sounds/background.ogg")
			))
			throw (std::runtime_error(output.str()));
	}
	catch (std::runtime_error e)
	{
		gameStatus = GameState::GameOver;
		initErrorWindow(e);
		exit(0);
	}
}

void Game::pollEvents()
{
	while (window->pollEvent(ev)) 
	{
		switch (ev.type)
		{
		case Event::Closed:
			window->close();
			break;
		case Event::KeyPressed:
			if (ev.key.code == Keyboard::Escape)
				window->close();
		}		
	}
}	

void Game::moveView()
{
	//move view up when player moves up
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
			gameOver();
			return;
		}

		if (obstacles.at(i)->checkStarColision(player->getBounds()))
		{
			score++;
			getPointSound.play();
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
		//rectangle ring
		case 1:
			obstacles.push_back(new ObstacleRingOfRectangles(yPosition, starTexture, colorSwitchTexture));
			break;
		//square
		case 2:
			obstacles.push_back(new ObstacleSquare(yPosition, starTexture, colorSwitchTexture));
			break;
		//line
		case 3:
			obstacles.push_back(new ObstacleLine(yPosition, starTexture, colorSwitchTexture));
			break;

	}
}

void Game::obstacleRemover()
{
	//remove obstacles that are out of view
	if (!obstacles.empty() && obstacles.front()->getYPosition() > view->getCenter().y + 0.8f * WINDOW_HEIGHT)
	{
		delete obstacles.front();
		obstacles.erase(obstacles.begin());
	}
}

void Game::checkOutOfMapCondition()
{
	//check if player is out of bounds
	if ((player != nullptr) && (player->getPosition().y > view->getCenter().y + 0.6f * WINDOW_HEIGHT || (player->getPosition().y < -100000.f)))
	{
		gameOver();
	}
}

Game::Game()
{
	loadFiles();
	initVariables();
	initWindow();

	//tymczasowo dopoki nie ma menu
	gameOver();
}

Game::~Game()
{
	//clear obstacle container
	for (int i = 0; i < obstacles.size(); i++)
	{
		delete obstacles.at(i);
	}

	delete player;
	delete pointCounter;
	delete view;
	delete gameOverScreen;
	delete window;	
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

const bool Game::running() const
{
	return window->isOpen();
}

void Game::update()
{
	pollEvents();
	switch (gameStatus) 
	{
		case GameState::Play:
			player->update(window);
			moveView();
			pointCounter->update(view->getCenter(), score);	
			obstacleGenerator();
			obstacleRemover();
			updateObstacles();
			checkColisions();
			checkOutOfMapCondition();
			break;
		case GameState::GameOver:
			gameOverScreen->update(window);
			if (gameOverScreen->backToMenuPressed(window))
			{
				sf::sleep(milliseconds(250));
				initNewGame();
			}
			break;
	}
}

void Game::render()
{
	window->clear(Color(44, 50, 66));
	window->setView(*view);
	//Render game here
	switch (gameStatus) 
	{
		case GameState::Play:
			player->render(window);
			renderObstacles();
			pointCounter->render(window);
		break;
		case GameState::GameOver:
			gameOverScreen->render(window);
			break;
	}
	window->display();
}