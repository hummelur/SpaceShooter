#include "CollisionHandler.h"

CollisionHandler * CollisionHandler::sm_instance = new CollisionHandler();

CollisionHandler::CollisionHandler(){}

CollisionHandler::~CollisionHandler(){}

CollisionHandler * CollisionHandler::instance() {
	return sm_instance;
}

bool CollisionHandler::Collision(const Vector2D posE, int we, int he,
								 const Vector2D posB, int wb, int hb) 
{
	return posE.x + we >= posB.x && posE.x <= posB.x + wb &&
		   posE.y + he >= posB.y && posE.y <= posB.y + hb;
}
