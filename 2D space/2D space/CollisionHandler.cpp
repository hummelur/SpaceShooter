#include "CollisionHandler.h"

CollisionHandler::CollisionHandler(){}

CollisionHandler::~CollisionHandler(){}

bool CollisionHandler::Collision(const Vector2D posE, int we, int he,
								 const Vector2D posB, int wb, int hb) 
{
	if (posE.x + we > posB.x && posE.x < posB.x + wb &&
		posE.y + he > posB.y && posE.y < posB.y + hb) {
		return true;
	} else {
		return false;
	}
}