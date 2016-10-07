#ifndef INCLUDED_COLLISIONHANDLER
#define INCLUDED_COLLISIONHANDLER

#include "Vector2D.h"
#include "EnemyHandler.h"
#include "BulletHandler.h"
#include "GameObject.h"
#include <vector>

class CollisionHandler {
public:
	static CollisionHandler * instance();
	CollisionHandler();
	~CollisionHandler();
	bool Collision(const Vector2D posE, int ew, int eh, 
				   const Vector2D posB, int bw, int bh);

private:
	static CollisionHandler * sm_instance;
};
#endif // !INCLUDED_COLLISIONHANDLER
