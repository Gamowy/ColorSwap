#pragma once
#include "ColorSwap.h"
#include "GameOverScreen.h"
#include "Player.h"
#include "Obstacle.h"
#include "ObstacleWindmill.h"
#include "ObstacleRingOfRectangles.h"
#include "ObstacleSquare.h"
#include "ObstacleLine.h"
#include "PointCounter.h"
#include"MainMenu.h"

using namespace sf;

//Possible game states
enum GameState { Menu, Play, GameOver, Error };
//Integer distribution for random obstacle generation
static std::uniform_int_distribution<int> obstacleRandomPick(0, 3);

class Game
{
private:
	//Window variables
	RenderWindow* window;
	VideoMode videoMode;
	View* view;
	PointCounter* pointCounter;
	MainMenu* menu;

	//Game variables
	unsigned int score;
	Event ev;
	GameState gameStatus;
	Player* player;
	GameOverScreen* gameOverScreen;
	std::vector<Obstacle*> obstacles;

	//Files to load
	std::wfstream scoresFile;
	Image windowIcon;
	Texture starTexture;
	Texture colorSwitchTexture;
	Font font;
	SoundBuffer jumpSoundFile;
	SoundBuffer getPointSoundFile;
	SoundBuffer gameOverSoundFile;
	Music backgroundMusic;

	Sound getPointSound;
	Sound gameOverSound;

	//Private methods
	void initVariables();
	void initWindow();
	void initNewGame();
	void gameOver();
	void initErrorWindow(std::string error);
	void loadFiles();
	void pollEvents();
	void moveView();
	void checkColisions();
	void obstacleGenerator();
	void createObstacle(float yPosition);
	void obstacleRemover();
	void checkOutOfMapCondition();
	void renderObstacles();
	void updateObstacles();

public:
	Game();
	virtual ~Game();

	const bool running() const;
	void update();
	void render();
};