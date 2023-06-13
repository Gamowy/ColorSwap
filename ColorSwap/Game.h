#pragma once
#include "ColorSwap.h"
#include "MainMenu.h"
#include "GameOverScreen.h"
#include "Player.h"
#include "Obstacle.h"
#include "ObstacleWindmill.h"
#include "ObstacleRingOfRectangles.h"
#include "ObstacleSquare.h"
#include "ObstacleLine.h"
#include "ObstacleCrusher.h"
#include "ObstacleElevator.h"
#include "PointCounter.h"
#include "ScoresFile.h"

using namespace sf;

//Possible game states
enum GameState { Menu, Play, GameOver, Error };
//Integer distribution for random obstacle generation
static std::uniform_int_distribution<int> obstacleRandomPick(0, 5);

class Game
{
private:
	//Window variables
	VideoMode videoMode;
	RenderWindow* window;
	View* view;
	PointCounter* pointCounter;
	MainMenu* menu;
	GameOverScreen* gameOverScreen;

	//Game variables
	unsigned int score;
	Player* player;
	std::vector<Obstacle*> obstacles;
	Event ev;
	GameState gameStatus;
	
	//Files to load
	ScoresFile* leaderboard;
	Image windowIcon;
	Texture starTexture;
	Texture colorSwitchTexture;
	Font font;
	SoundBuffer popSound;
	SoundBuffer getPointSoundFile;
	SoundBuffer gameOverSoundFile;
	Sound getPointSound;
	Sound gameOverSound;
	Music backgroundMusic;

	//Private methods
	void initVariables();
	void initWindow();
	void loadFiles();
	void initErrorWindow(std::string error);
	void initNewGame();
	void gameOver();
	void pollEvents();
	void moveView();
	void checkColisions();
	void checkOutOfMapCondition();
	void obstacleGenerator();
	void createObstacle(float yPosition);
	void obstacleRemover();
	void renderObstacles();
	void updateObstacles();

public:
	Game();
	virtual ~Game();

	const bool running() const;
	void update();
	void render();
};