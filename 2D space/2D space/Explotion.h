#ifndef INCLUDED_EXPLOTION
#define INCLUDED_EXPLOTION

#include "Timer.h"
#include "SDL_image.h"
#include "SDL.h"
#include "GameObject.h"
#include "Vector2D.h"
#include "game.h"

class Explotion : public GameObject {
public:
	Explotion(Vector2D pos);
	virtual ~Explotion();
	virtual void draw() const;
	virtual void update();
	virtual Vector2D getPos() const;
	inline virtual int getWidth() const { return _width; }
	inline virtual int getHeight() const { return _height; }

private:
	Vector2D _pos;
	
	int _width;
	int _height;
	int _speed;

	Timer *_timer;

	SDL_Texture *_texture;
};
#endif // !INCLUDED_EXPLOTION
