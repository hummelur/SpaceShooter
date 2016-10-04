#include "player.h"
#include "game.h"
#include "BulletHandler.h"
#include <iostream>

Player * Player::sm_instance = new Player();

Player::Player() :
	_posx(100),
	_posy(500),
	_pos(_posx, _posy){
	
	_width = 25;
	_height = 25;
	_speed = 5;
}

Player::~Player() {
}

Player * Player::instance() {
	return sm_instance;
}

void Player::setPosY(int posy) {
	_pos.y = posy;
}

void Player::setPosX(int posx) {
	_pos.x = posx;
}

void Player::setWidth(int width) {
	_width = width;
}

void Player::setHeight(int height) {
	_height = height;
}

Vector2D Player::getPos() const {
	return _pos;
}

void Player::movement( int speed, int dir ) {
	//Kollar efter vilken dir som ska köras och använder hastigheten för att röra den
	switch (dir) {
		case 1: // Vänster
			_pos.x = _pos.x + speed;
			break;
		case 2: // Höger
			_pos.x = _pos.x + speed;
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

	// Sätter storleken på recten och positionen
	rect.w = _width;
	rect.h = _height;
	rect.x = _pos.x;
	rect.y = _pos.y;

	SDL_SetRenderDrawColor(Game::instance()->getRenderer(), 150, 0, 210, 10); // Sätter färgen för recten
	SDL_RenderFillRect(Game::instance()->getRenderer(), &rect);				  // Applicerar färgen till rectanglen
	
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
			default:
				break;
		}

		if (event.key.keysym.sym == SDLK_SPACE) {
			//avfyra vapen
			BulletHandler::instance()->addBullet(new Bullet(_pos));
		}
	}
}