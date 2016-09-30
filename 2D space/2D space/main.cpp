#include "game.h"

int main(int argc, char* args[]) {

	Game::instance()->init("Space Invaders ala Olltard", 600, 600); // Skapar f�nstret

	while (Game::instance()->isRunning()) { //Whileloop som k�rs s� l�nge f�nstret �r �ppet
		Game::instance()->update(); // Uppdaterar allt
		Game::instance()->render(); // renderar allt
	}

	return 0;
}