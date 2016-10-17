#include "Powerup.h"

Powerup::Powerup() :
	_speed(2),
	_sideSpeed(5),
	_width(30),
	_height(30) {
	_pos.x = Random::instance()->getRandom(20, 600);
	_pos.y = -10;

	// Laddar in bilden 
	// (Kanske ska �ndra detta s� man bara laddar in bilden en g�ng ist�llet f�r m�nga g�nger)
	auto surface = IMG_Load("images/pup.png");

	// L�gger in bilden till texturen 
	_texture = SDL_CreateTextureFromSurface(Game::instance()->getRenderer(), surface);

	// Kollar om texturen skapades p� r�tt s�tt 
	if (!_texture) {
		printf("Failed to create texture");
	}

	// Frig�r ytan
	SDL_FreeSurface(surface);
}

Powerup::~Powerup() {
	SDL_DestroyTexture(_texture);
	IMG_Quit();
}

Vector2D Powerup::getPos() const {
	return _pos;
}

void Powerup::draw() const {
	//skapar ny rect
	SDL_Rect rect;

	// S�tter storleken p� recten och positionen
	rect.w = _width;
	rect.h = _height;
	rect.x = _pos.x;
	rect.y = _pos.y;

	if (_texture) {
		SDL_RenderCopy(Game::instance()->getRenderer(), _texture, nullptr, &rect);
	}
	else {
		SDL_SetRenderDrawColor(Game::instance()->getRenderer(), 255, 0, 200, 10); // S�tter f�rgen f�r recten
		SDL_RenderFillRect(Game::instance()->getRenderer(), &rect);				  // Applicerar f�rgen till rectanglen
	}
}

void Powerup::update() {
	_pos.y += _speed;
	_pos.x += _sideSpeed;

	if (_pos.x <= 0)
		_sideSpeed = -_sideSpeed;
	else if (_pos.x >= 600 - _width)
		_sideSpeed = -_sideSpeed;
}

int Powerup::getWidth() const {
	return _width;
}

int Powerup::getHeight() const {
	return _height;
}