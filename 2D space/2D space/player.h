#ifndef INCLUDED_PLAYER
#define INCLUDED_PLAYER

#include "window.h"
#include "entity.h"
#include "SDL.h"

class Player : public Entity {
public:
	Player();
	virtual ~Player();
	virtual void draw() const;
	virtual void update();
	void movement(int speed, int dir);
	void eventHandler(SDL_Event &event);


private:
	int _width = 25;
	int _height = 25;
	int _dir = 1;
	int _speed = 5;

	float _posx;
	float _posy;
	
	

	SDL_Renderer *_renderer = nullptr;
};

#endif // !INCLUDED_PLAYER
