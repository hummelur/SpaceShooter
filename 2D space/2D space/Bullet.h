#ifndef INCLUDED_BULLET
#define INCLUDED_BULLET

#include "GameObject.h"
#include "SDL.h"
#include "Vector2D.h"
#include "player.h"
#include <vector>


class Bullet : public GameObject{
public:
	Bullet();
	Bullet(const Vector2D pos);
	virtual ~Bullet();
	virtual Vector2D getPos() const;
	virtual void draw() const;
	virtual void update();

private:
	Vector2D _pos;
	float _posx;
	float _posy;
	int _speed;
	int _width;
	int _height;
};
#endif // !INCLUDED_BULLET