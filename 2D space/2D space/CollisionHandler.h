#ifndef INCLUDED_COLLISIONHANDLER
#define INCLUDED_COLLISIONHANDLER

#include "Vector2D.h"
#include "EnemyHandler.h"
#include "BulletHandler.h"
#include "ExplotionManager.h"
#include "GameObject.h"
#include <vector>
#include "Explotion.h"

class CollisionHandler {
public:
	static CollisionHandler * instance();
	CollisionHandler();
	~CollisionHandler();
	bool Collision(const Vector2D posE, int ew, int eh, 
				   const Vector2D posB, int bw, int bh);
	void CheckObjCollision();

private:
	typedef std::vector<GameObject*> Explotions;
	Explotions *_explotion;

	static CollisionHandler * sm_instance;
};
#endif // !INCLUDED_COLLISIONHANDLER
