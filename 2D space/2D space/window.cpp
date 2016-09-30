#include "window.h"
#include <iostream>

Window::Window(const std::string &title, int width, int height) :
	_title(title), 
	_width(width),
	_height(height) {
	_closed = !init();
}

Window::~Window() { // Tarbort window och renderer
	SDL_DestroyRenderer(_renderer);
	SDL_DestroyWindow(_window);
	SDL_Quit();
}

bool Window::init() {

	if (SDL_Init(SDL_INIT_VIDEO) != 0) { // Kollar om SDL video initeras 
		std::cout << "Failed to initiialaize SDL. ";
		return 0;
	}

	// Skapar fönstert
	_window = SDL_CreateWindow(
		_title.c_str(),
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		_width, _height,
		0
	);

	
	if (_window == nullptr) { // Kollar om fönstret skapades 
		std::cout << "Failed to create window.";
		return 0;
	}
	
	_renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_PRESENTVSYNC); // Skapar en renderer

	if (_renderer == nullptr) { // Kollar om renderern skapades
		std::cout << "Failed to initialise renderer. " << std::endl;
		return 0;
	}

	return true; // returnerar true om allt initerar allt
}



void Window::pollEvents() { // Lyssnar efter events
	SDL_Event event;

	if (SDL_PollEvent(&event)) {

		switch (event.type) { //Switch för att kolla efter poll events med sdls egna input system
		case SDL_QUIT:
			_closed = true;
			break;
		default:
			break;
		}
	}
}

void Window::clear() const { // Skriver ut bakgrund 

	SDL_SetRenderDrawColor(_renderer, 0, 0, 200, 255); // sätter färgen vi vill visa 
	SDL_RenderClear(_renderer); // Sätter färgen
	SDL_RenderPresent(_renderer); //Ritar ut det som ska ritas ut
	

	//SDL_Rect rect;

	//rect.w = 120;
	//rect.h = 120;
	//rect.x = _width / 2 - (rect.w / 2);
	//rect.y = _height / 2 - (rect.h / 2);

	//SDL_SetRenderDrawColor(_renderer, 200, 0, 200, 255); // sätter färgen på rectangeln
	//SDL_RenderFillRect(_renderer, &rect); //Fyller i rectangeln 
	

	
}