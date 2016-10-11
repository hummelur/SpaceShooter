#include "player.h"
#include "game.h"
#include "BulletHandler.h"
#include <iostream>

Player * Player::sm_instance = new Player();

Player::Player() :
	_posx(100),
	_posy(500),
	_pos(_posx, _posy){
	_speed = 6;
	keyStates = SDL_GetKeyboardState(0);

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

void Player::setTexture() {
	auto surface = IMG_Load("images/player.png");

	if (!surface) {
		printf(IMG_GetError());
	}

	_texture = SDL_CreateTextureFromSurface(Game::instance()->getRenderer(), surface);

	if (!_texture) {
		printf("Failed to create texture");
	}
	SDL_FreeSurface(surface);
}

void Player::givePoints(int points) {
	_points += points;
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
			_pos.y = _pos.y + speed;
			break;
		default:
			break;
	}
}

void Player::update() {
	
	// Timer
	if (_timerunning == true) {
		// Om klassen retunerar true så ställs 
		//_timerunning till false och spelaren kan skjuta igen
		if (timer()) {
			_timerunning = false;
			_time = 130;
		} else {
			_timerunning = true;
		}
	}


	// Movement and fireing 
	if (_left) {
		if(_pos.x > 0)
			movement(-_speed, 1);
	} 
	if (_right) {
		if(Game::instance()->getWindowWidth() - _width > _pos.x)
			movement(_speed, 1);
	}
	if (_up) {
		if (0 < _pos.y)
			movement(-_speed, 2);
	}
	if (_down) {
		if(Game::instance()->getWindowHeight() > _pos.y + _height)
			movement(_speed, 2);
	}
	if (_fireing) {
		if (_timerunning == false) {
			BulletHandler::instance()->addBullet(new Bullet(_pos));
			_timerunning = true;
		}
	}
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
	if (_texture) {
		SDL_RenderCopy(Game::instance()->getRenderer(), _texture, nullptr, &rect);
	}
	else {
		SDL_SetRenderDrawColor(Game::instance()->getRenderer(), 255, 255, 200, 10); // Sätter färgen för recten
		SDL_RenderFillRect(Game::instance()->getRenderer(), &rect);				  // Applicerar färgen till rectanglen

	}
	
}

void Player::eventHandler(SDL_Event &event) {


	if (event.type == SDL_KEYDOWN || event.type == SDL_KEYUP)
	{
		keyStates = SDL_GetKeyboardState(0);
	}

	if (keyStates != 0)
	{
		if (keyStates[SDL_SCANCODE_SPACE] == 1)
		{
			_fireing = true;
		} else {
			_fireing = false;
		}
		if (keyStates[SDL_SCANCODE_RIGHT] == 1 || keyStates[SDL_SCANCODE_D] == 1)
		{
			_right = true;
		} else {
			_right = false;
		}

		if (keyStates[SDL_SCANCODE_LEFT] == 1 || keyStates[SDL_SCANCODE_A] == 1)
		{
			_left = true;
		}else {
			_left = false;
		}

		if (keyStates[SDL_SCANCODE_UP] == 1 || keyStates[SDL_SCANCODE_W] == 1)
		{
			_up = true;
		}
		else {
			_up = false;
		}

		if (keyStates[SDL_SCANCODE_DOWN] == 1 || keyStates[SDL_SCANCODE_S] == 1)
		{
			_down = true;
		}
		else {
			_down = false;
		}

	}
}

bool Player::timer() {
	// Räknar ner 
	_time -= 10;
	
	// Kollar om time är mindre än noll
	// Om den är de retuneras true
	if (_time <= 0) {
		return true;
	} else {
		return false;
	}
	
}