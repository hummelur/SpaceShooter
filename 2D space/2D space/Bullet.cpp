#include "Bullet.h"
#include "game.h"
#include "player.h"

Bullet * Bullet::sm_instance = new Bullet();

Bullet::Bullet(){}

Bullet::Bullet(const Vector2D pos) :
	_width(40),
	_pos(pos),
	_speed(14),
	_height(40) {
	_pos.x = _pos.x + (Player::instance()->getWidth() / 2) - (_width / 2);
	
	// Laddar in bilden 
	// (Kanske ska �ndra detta s� man bara laddar in bilden en g�ng ist�llet f�r m�nga g�nger)
	auto surface = IMG_Load("images/bullet.png");
	
	// Kollar om de gick att ladda filen
	if (!surface) {
		printf(IMG_GetError());
	}

	// L�gger in bilden till texturen 
	_texture = SDL_CreateTextureFromSurface(Game::instance()->getRenderer(), surface);

	// Kollar om texturen skapades p� r�tt s�tt 
	if (!_texture) {
		printf("Failed to create texture");
	}

	// Frig�r ytan
	SDL_FreeSurface(surface);
}

Bullet::~Bullet(){
	SDL_DestroyTexture(_texture);
	IMG_Quit();
}

Bullet * Bullet::instance() {
	return sm_instance;
}

Vector2D Bullet::getPos() const {
	return _pos;
}

void Bullet::draw() const {
	//skapar ny rect
	SDL_Rect rect;

	// S�tter storleken p� recten och positionen
	rect.w = _width;
	rect.h = _height;
	rect.x = _pos.x;
	rect.y = _pos.y;

	if (_texture) {
		SDL_RenderCopy(Game::instance()->getRenderer(), _texture, nullptr, &rect);
	} else {
		SDL_SetRenderDrawColor(Game::instance()->getRenderer(), 255, 255, 200, 10); // S�tter f�rgen f�r recten
		SDL_RenderFillRect(Game::instance()->getRenderer(), &rect);				  // Applicerar f�rgen till rectanglen

	}
}

void Bullet::update() {
	_pos.y -= _speed;
}

int Bullet::getHeight() const {
	return _height;
}

int Bullet::getWidth() const {
	return _width;
}