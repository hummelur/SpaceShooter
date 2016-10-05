#ifndef INCLUDED_PLAYER
#define INCLUDED_PLAYER

#include "GameObject.h"
#include "SDL.h"
#include "Vector2D.h"

class Player : public GameObject {
public:

	static Player * instance();

	Player();
	virtual ~Player();
	virtual void draw() const;
	virtual void update();
	virtual Vector2D getPos() const;
	
	// Events
	void movement(int speed, int dir);
	void eventHandler(SDL_Event &event);
	
	//Set and gets
	void setPosY(int posy);
	void setPosX(int posx);
	void setWidth(int width);
	void setHeight(int height);
	inline int getWidth() const { return _width; }
	inline int getHeight() const { return _height; }
	
	// Timer
	bool timer();

private:
	int _width = 25;
	int _height = 25;
	int _dir = 1;
	int _speed = 5;

	Vector2D _pos;

	float _posx;
	float _posy;

	int _time = 130;
	bool _timerunning = false;

	// Keystates
	const Uint8* keyStates;
	
	// Movement bools
	bool _left = false;
	bool _right = false;
	bool _fireing = false;

	static Player * sm_instance;
};

#endif // !INCLUDED_PLAYER
