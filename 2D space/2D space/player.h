#ifndef INCLUDED_PLAYER
#define INCLUDED_PLAYER

#include "GameObject.h"
#include "SDL.h"
#include "SDL_image.h"
#include "Timer.h"
#include "Vector2D.h"
#include "GameState.h"

class Player : public GameObject {
public:

	static Player * instance();

	Player();
	virtual ~Player();
	virtual void draw() const;
	virtual void update();
	virtual Vector2D getPos() const;
	inline int getHealth() const { return _lives; }
	void setHealth(int hp);
	// Events
	void movement(int speed, int dir);
	void eventHandler(SDL_Event &event);
	
	//Setters
	void setPosY(int posy);
	void setPosX(int posx);
	void setWidth(int width);
	void setHeight(int height);
	void setTexture();
	void givePoints(int points);
	void setPowerup(bool);

	//Getters
	inline int getWidth() const { return _width; }
	inline int getHeight() const { return _height; }
	inline int getPoints() const { return _points; }
	inline bool getPowerup() const { return _powerup; }
	int getPowerUpTime() const;
	
	// Timer
	bool timer();

private:
	int _width = 50;
	int _height = 50;
	int _dir = 1;
	int _speed = 5;
	int _points = 0;
	int _lives;
	

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
	bool _up = false;
	bool _down = false;
	bool _fireing = false;
	bool _powerup = false;

	// Timer
	Timer *_timer;

	//Texture
	SDL_Texture *_texture;

	static Player * sm_instance;
};

#endif // !INCLUDED_PLAYER
