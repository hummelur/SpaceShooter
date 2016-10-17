#include "Bullet.h"
#include "game.h"
#include "player.h"

Bullet * Bullet::sm_instance = new Bullet();

Bullet::Bullet(){}

Bullet::Bullet(const Vector2D pos, bool right, bool left) :
	_width(20),
	_pos(pos),
	_speed(14),
	_sideSpeed(4),
	_height(20),
	_leftBullet(right),
	_rightBullet(left){
	_pos.x = _pos.x + (Player::instance()->getWidth() / 2) - (_width / 2);
	
	// Laddar in bilden 
	// (Kanske ska ändra detta så man bara laddar in bilden en gång istället för många gånger)
	auto surface = IMG_Load("images/pbullet.png");

	// Lägger in bilden till texturen 
	_texture = SDL_CreateTextureFromSurface(Game::instance()->getRenderer(), surface);

	// Kollar om texturen skapades på rätt sätt 
	if (!_texture) {
		printf("Failed to create texture");
	}

	// Frigör ytan
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

	// Sätter storleken på recten och positionen
	rect.w = _width;
	rect.h = _height;
	rect.x = _pos.x;
	rect.y = _pos.y;

	if (_texture) {
		SDL_RenderCopy(Game::instance()->getRenderer(), _texture, nullptr, &rect);
	} else {
		SDL_SetRenderDrawColor(Game::instance()->getRenderer(), 255, 255, 200, 10); // Sätter färgen för recten
		SDL_RenderFillRect(Game::instance()->getRenderer(), &rect);				  // Applicerar färgen till rectanglen

	}
}

void Bullet::update() {
	_pos.y -= _speed;
	if (_rightBullet) {
		_pos.x += _sideSpeed;
	} else if (_leftBullet) {
		_pos.x -= _sideSpeed;
	}
}

int Bullet::getHeight() const {
	return _height;
}

int Bullet::getWidth() const {
	return _width;
}