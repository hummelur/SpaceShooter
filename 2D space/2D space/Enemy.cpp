#include "Enemy.h"
#include "player.h"
#include "random.h"

Enemy::Enemy(float posx) :
	_pos(posx, -30), // Kör random x position
	_width(35),
	_height(35),
	_speed(3){
	
}

Enemy::~Enemy() {
}

void Enemy::update() {
	movement();
}

void Enemy::draw() const {
	SDL_Rect rect;

	rect.x = _pos.x;
	rect.y = _pos.y;
	rect.w = _width;
	rect.h = _height;

	SDL_SetRenderDrawColor(Game::instance()->getRenderer(), 100, 255, 100, 255);
	SDL_RenderFillRect(Game::instance()->getRenderer(), &rect);
}

Vector2D Enemy::getPos() const {
	return _pos;
}

void Enemy::movement(){
	_pos.y += _speed;
}