#ifndef INCLUDED_ENEMYBULLET
#define INCLUDED_ENEMYBULLET

#include "GameObject.h"
#include "SDL.h"
#include "SDL_image.h"
#include "Vector2D.h"
#include "game.h"

class EnemyBullet : public GameObject {
public:
	static EnemyBullet * instance();

	EnemyBullet();
	EnemyBullet(const Vector2D pos);
	virtual ~EnemyBullet();
	virtual Vector2D getPos() const;
	virtual void draw() const;
	virtual void update();
	virtual int getWidth() const;
	virtual int getHeight() const;

private:
	Vector2D _pos;

	int _speed;
	int _width;
	int _height;

	SDL_Texture *_texture;

	static EnemyBullet * sm_instance;
};
#endif // !INCLUDED_ENEMYBULLET
