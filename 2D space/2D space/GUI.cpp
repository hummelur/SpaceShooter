#include "GUI.h"

GUI * GUI::sm_instance = new GUI();


GUI::GUI() :
	screen(NULL),
	font(NULL){
	color = { 255, 255, 255, 255 };
}

GUI * GUI::instance() {
	return sm_instance;
}

void GUI::init() {
	
}

void GUI::draw() { 
	// Sätter storleken för text och bredd på den
	SDL_Rect location = { 10, 10, 200 , 30 };
	
	// Laddar fonten
	font = TTF_OpenFont("font/olltard.ttf", 60);
	if (font == nullptr) {
		printf("FAiled to load font \n");
		printf(TTF_GetError());
	}

	// Sätter texten till surface
	std::string s = std::to_string(Player::instance()->getPoints());
	s = "Points: " + s;
	
 	points = TTF_RenderText_Blended(font, s.c_str(), color);
	if (points == nullptr) {
		TTF_CloseFont(font);
	}
	texture = SDL_CreateTextureFromSurface(Game::instance()->getRenderer(), points);
	if (texture == nullptr) {
		printf("Fail");
	}

	// Skriver ut texturen som gjordes i init
	SDL_RenderCopy(Game::instance()->getRenderer(), texture, nullptr, &location);
	SDL_FreeSurface(points);
	SDL_DestroyTexture(texture);
	TTF_CloseFont(font);

}


/*

// DENNA SKA VARA I TTF FONTS
TTF_Font *times;

times = TTF_OpenFont("CircleOfDust.ttf", 20);

if (!times) {
printf("ERROR");
}
SDL_Color color = { 255, 255, 255 };

SDL_Surface *UIsurface = TTF_RenderText_Solid(times, "Points: alibaba", color);
SDL_Surface *window = SDL_GetWindowSurface(m_window);


SDL_BlitSurface(UIsurface, NULL, window, NULL);
SDL_FreeSurface(UIsurface);
TTF_CloseFont(times);

*/