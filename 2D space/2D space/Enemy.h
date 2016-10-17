#ifndef INCLUDED_ENEMY
#define INCLUDED_ENEMY

#include "GameObject.h"
#include "Vector2D.h"
#include "SDL.h"
#include "SDL_image.h"
#include "game.h"
#include "Timer.h"
#include "EnemyBullet.h"

class Enemy : public GameObject {
public:
	Enemy(float posx);
	virtual ~Enemy();
	virtual void update();
	virtual void draw() const;
	virtual Vector2D getPos() const;
	inline virtual int getWidth() const { return _width; }
	inline virtual int getHeight() const { return _height; }

	void addBullet(GameObject *enemyBullet);

	void movement();
private:
	Vector2D _pos;
	int _speed;
	int _width;
	int _height;
	int _health;
	float _startPosX; // Denna ska vara random

	Timer *_timer;

	SDL_Texture *_texture;
};
#endif // !INCLUDED_ENEMY
