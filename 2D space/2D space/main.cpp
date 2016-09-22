#include "SDL.h"
#include <iostream>

int main(int argc, char* args[]) {

	SDL_Window *window = nullptr;

	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		std::cout << "Error video init Error!" << SDL_GetError() << std::endl;
	}
	else {
		window = SDL_CreateWindow("SpaceShooter", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_SHOWN);
		if (window = NULL)
			std::cout << "Window creation error: " << SDL_GetError() << std::endl;
		else {
			SDL_UpdateWindowSurface(window);
			SDL_Delay(6000);
		}
	}

	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}