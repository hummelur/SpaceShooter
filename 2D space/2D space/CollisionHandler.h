#ifndef INCLUDED_COLLISIONHANDLER
#define INCLUDED_COLLISIONHANDLER

#include "Vector2D.h"

class CollisionHandler {
public:
	CollisionHandler();
	~CollisionHandler();
	bool Collision(const Vector2D posE, int ew, int eh, 
				   const Vector2D posB, int bw, int bh);
};
#endif // !INCLUDED_COLLISIONHANDLER
