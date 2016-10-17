#include "EnemyBullet.h"

EnemyBullet * EnemyBullet::sm_instance = new EnemyBullet();

EnemyBullet::EnemyBullet(){}

EnemyBullet::EnemyBullet(const Vector2D pos):
	_width(40),
	_height(40),
	_pos(pos),
	_speed(8){

	// Laddar in bilden 
	// (Kanske ska ändra detta så man bara laddar in bilden en gång istället för många gånger)
	auto surface = IMG_Load("images/ebullet.png");

	// Lägger in bilden till texturen 
	_texture = SDL_CreateTextureFromSurface(Game::instance()->getRenderer(), surface);

	// Frigör ytan
	SDL_FreeSurface(surface);

}

EnemyBullet::~EnemyBullet() {
	SDL_DestroyTexture(_texture);
	IMG_Quit();
}

EnemyBullet * EnemyBullet::instance() {
	return sm_instance;
}

Vector2D EnemyBullet::getPos() const {
	return _pos;
}

void EnemyBullet::draw() const {
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
		SDL_SetRenderDrawColor(Game::instance()->getRenderer(), 255, 255, 200, 10); // Sätter färgen för recten
		SDL_RenderFillRect(Game::instance()->getRenderer(), &rect);				  // Applicerar färgen till rectanglen

	}
}

void EnemyBullet::update() {
	_pos.y += _speed;
}

int EnemyBullet::getHeight() const {
	return _height;
}

int EnemyBullet::getWidth() const {
	return _width;
}