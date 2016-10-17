#include "game.h"
#include "GameState.h"
int main(int argc, char* args[]) {

	Game::instance()->init("Space Invaders ala Olltard", 600, 800); // Skapar fönstret

	while (Game::instance()->isRunning()) { //Whileloop som körs så länge fönstret är öppet
		Game::instance()->update(); // Uppdaterar allt
		Game::instance()->render(); // renderar allt
	}
	return 0;
}