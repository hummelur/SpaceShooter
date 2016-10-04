#ifndef INCLUDED_BULLETHANDLER
#define INCLUDED_BULLETHANDLER

#include "player.h"
#include "Bullet.h"
#include "GameObject.h"
#include "game.h"

class BulletHandler {
public:
	static BulletHandler * instance();
	
	BulletHandler();
	~BulletHandler();
	
	void addBullet(GameObject *bullet);
	void delBullet();
	void draw();
	void update();
	
	typedef std::vector<GameObject*> bullets;
	bullets m_bullets;

private:
	float posx;
	static BulletHandler * sm_instance;

};

#endif // !INLCUDED_BULLETHANDLER
