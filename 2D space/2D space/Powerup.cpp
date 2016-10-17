#include "Powerup.h"

Powerup::Powerup() :
	_speed(2),
	_sideSpeed(5),
	_width(30),
	_height(30) {
	_pos.x = Random::instance()->getRandom(20, 600);
	_pos.y = -10;

	// Laddar in bilden 
	// (Kanske ska ändra detta så man bara laddar in bilden en gång istället för många gånger)
	auto surface = IMG_Load("images/pup.png");

	// Lägger in bilden till texturen 
	_texture = SDL_CreateTextureFromSurface(Game::instance()->getRenderer(), surface);

	// Kollar om texturen skapades på rätt sätt 
	if (!_texture) {
		printf("Failed to create texture");
	}

	// Frigör ytan
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

	// Sätter storleken på recten och positionen
	rect.w = _width;
	rect.h = _height;
	rect.x = _pos.x;
	rect.y = _pos.y;

	if (_texture) {
		SDL_RenderCopy(Game::instance()->getRenderer(), _texture, nullptr, &rect);
	}
	else {
		SDL_SetRenderDrawColor(Game::instance()->getRenderer(), 255, 0, 200, 10); // Sätter färgen för recten
		SDL_RenderFillRect(Game::instance()->getRenderer(), &rect);				  // Applicerar färgen till rectanglen
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