#ifndef INCLUDED_POWERUP
#define INCLUDED_POWERUP

#include "GameObject.h"
#include "Vector2D.h"
#include <vector>
#include "SDL.h"
#include "SDL_image.h"
#include "random.h"
#include "game.h"

class Powerup : public GameObject {
public:
	Powerup();
	virtual ~Powerup();
	virtual void update();
	virtual void draw() const;
	virtual Vector2D getPos() const;
	virtual int getWidth() const;
	virtual int getHeight() const;

private: 
	Vector2D _pos;
	int _speed;
	int _sideSpeed;
	int _width;
	int _height;

	SDL_Texture *_texture;
};
#endif // !INCLUDED_POWERUP
