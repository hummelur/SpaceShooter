#include "Enemy.h"
#include "player.h"

Enemy::Enemy(float posx) :
	_pos(posx, -30), // Kör random x position
	_width(45),
	_height(45),
	_speed(3),
	_health(2){

	_timer = new Timer(Random::instance()->getRandom(40, 100));
	_timer->start(); // startar timern

	auto surface = IMG_Load("images/enemy.png");
	_texture = SDL_CreateTextureFromSurface(Game::instance()->getRenderer(), surface);

	if (!_texture) {
		printf("Failed to create texture");
	}
	SDL_FreeSurface(surface);
}

Enemy::~Enemy() {
	SDL_DestroyTexture(_texture);
	IMG_Quit();
}

void Enemy::update() {
	// Kollar om timern körs
	if (!_timer->isOver()) {
		_timer->isRunning(); // Kör timern
	} else {
		EnemyHandler::instance()->addEnemyBullet(new EnemyBullet(_pos));
		_timer->start();
	}
	movement();
}

void Enemy::draw() const {
	SDL_Rect rect;

	rect.x = _pos.x;
	rect.y = _pos.y;
	rect.w = _width;
	rect.h = _height;

	if (_texture) {
		SDL_RenderCopy(Game::instance()->getRenderer(), _texture, nullptr, &rect);
	}
	else {
		SDL_SetRenderDrawColor(Game::instance()->getRenderer(), 255, 255, 200, 10); // Sätter färgen för recten
		SDL_RenderFillRect(Game::instance()->getRenderer(), &rect);				  // Applicerar färgen till rectanglen

	}
}

Vector2D Enemy::getPos() const {
	return _pos;
}


void Enemy::movement(){
	_pos.y += _speed;
}

