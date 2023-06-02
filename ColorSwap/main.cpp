#include "ColorSwap.h"
#include "Game.h"


int main()
{
	//Init game
	Game game;

	while (game.running()) {
		game.update();
		game.render();
	}
}