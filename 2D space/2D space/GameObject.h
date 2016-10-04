#ifndef INCLUDED_GAMEOBJECT
#define INCLUDED_GAMEOBJECT

#include "Vector2D.h"

class GameObject {
public:
	GameObject();
	virtual ~GameObject() = 0;
	virtual void draw() const = 0;
	virtual void update() = 0;
	virtual Vector2D getPos() const = 0;
};
#endif // !INCLUDED_GAMEOBJECT
