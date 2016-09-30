#include "player.h"
#include "game.h"
#include <iostream>

Player::Player(){
	_width = 25;
	_height = 25;
	_posx = 100.0;
	_posy = 100.0;
	_speed = 5;
}

Player::~Player() {
}

void Player::movement( int speed, int dir ) {
	//Kollar efter vilken dir som ska k�ras och anv�nder hastigheten f�r att r�ra den
	switch (dir) {
		case 1: // V�nster
			_posx = _posx + speed;
			break;
		case 2: // H�ger
			_posx = _posx + speed;
			break;
		case 3: // Upp
			_posy = _posy + speed;
			break;
		case 4: // Ner
			_posy = _posy + speed;
			break;
		default:
			break;
	}
}

void Player::update() {

}

//Ritar ut spelarens rect (Ska vara en sprite senare)
void Player::draw() const {

	// Skapar en ny rect
	SDL_Rect rect;

	// S�tter storleken p� recten och positionen
	rect.w = _width;
	rect.h = _height;
	rect.x = _posx;
	rect.y = _posy;

	SDL_SetRenderDrawColor(Game::instance()->getRenderer(), 150, 0, 210, 10); // S�tter f�rgen f�r recten
	SDL_RenderFillRect(Game::instance()->getRenderer(), &rect);				  // Applicerar f�rgen till rectanglen
	//SDL_RenderPresent(Game::instance()->getRenderer());						  //Skriver ut recten
	
}

void Player::eventHandler(SDL_Event &event) {
	// Kollar efter knapptryckningar
	if (event.type == SDL_KEYDOWN) {
		switch (event.key.keysym.sym) {
			case SDLK_LEFT:
				movement(-_speed, 1);
				break;
			case SDLK_RIGHT:
				movement(_speed, 2);
				break;
			case SDLK_UP:
				movement(-_speed, 3);
				break;
			case SDLK_DOWN:
				movement(_speed, 4);
				break;
			default:
				break;
		}
	}
}