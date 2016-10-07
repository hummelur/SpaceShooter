#ifndef INCLUDED_BULLETHANDLER
#define INCLUDED_BULLETHANDLER

#include "player.h"
#include "Bullet.h"
#include "GameObject.h"
#include "game.h"
#include "EnemyHandler.h"
#include "Enemy.h"
#include "CollisionHandler.h"

class BulletHandler {
public:
	static BulletHandler * instance();
	
	BulletHandler();
	~BulletHandler();
	
	void addBullet(GameObject *bullet);
	void delBullet();
	void draw();
	void update();
	void collisionHandlerBullet(std::vector<GameObject*> &enemys);

	typedef std::vector<GameObject*> bullets;
	bullets m_bullets;

private:
	static BulletHandler * sm_instance;

};

#endif // !INLCUDED_BULLETHANDLER
