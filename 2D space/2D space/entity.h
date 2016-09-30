#ifndef INCLUDED_ENTITY
#define INCLUDED_ENTITY

class Entity {
public:
	Entity();
	virtual ~Entity();
	virtual void draw() const = 0;
	virtual void update() = 0;
	
};

#endif // !INCLUDED_ENTITY
