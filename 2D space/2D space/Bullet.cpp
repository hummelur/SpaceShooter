#include "Bullet.h"
#include "game.h"
#include "player.h"

Bullet::Bullet(){}

Bullet::Bullet(const Vector2D pos) :
	_width(10),
	_pos(pos),
	_speed(7),
	_height(10) {
	_pos.x = _pos.x + (Player::instance()->getWidth() / 2) - (_width / 2);
}

Bullet::~Bullet(){
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
	
	SDL_SetRenderDrawColor(Game::instance()->getRenderer(), 255, 255, 200, 10); // S�tter f�rgen f�r recten
	SDL_RenderFillRect(Game::instance()->getRenderer(), &rect);				  // Applicerar f�rgen till rectanglen

}

void Bullet::update() {
	if (_pos.y > 200) {
		_pos.y -= _speed;
	}
}