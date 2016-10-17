#include "Explotion.h"

Explotion::Explotion(Vector2D pos) :
	_pos(pos),
	_width(20),
	_height(20),
	_speed(4){
	_timer = new Timer(100);
	_timer->start();

	auto surface = IMG_Load("images/explotion.png");

	_texture = SDL_CreateTextureFromSurface(Game::instance()->getRenderer(), surface);

	if (!_texture) {
		printf("Failed to create texture");
	}
	SDL_FreeSurface(surface);

}

Explotion::~Explotion() {
	SDL_DestroyTexture(_texture);
	IMG_Quit();
}

Vector2D Explotion::getPos() const {
	return _pos;
}

void Explotion::update() {
	_width += _speed;
	_height += _speed;
	_pos.x -= _speed / 3;
	_pos.y -= _speed / 3;
}

void Explotion::draw() const {
	// Skapar en ny rect
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
