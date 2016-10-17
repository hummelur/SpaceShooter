#ifndef INCLUDED_POWERUPHANDLER
#define INCLUDED_POWERUPHANDLER

#include "Powerup.h"
#include "Timer.h"


class PowerupHandler {
public:
	static PowerupHandler * instance();

	PowerupHandler();
	~PowerupHandler();

	void addPowerup(GameObject *powup);
	void delPowerup();
	void draw();
	void update();
	void reset();

	typedef std::vector<GameObject*> Powerups;
	Powerups m_powerups;

private:
	Timer *_timer;
	static PowerupHandler * sm_instance;
};
#endif // !INCLUDED_POWERUPHANDLER
