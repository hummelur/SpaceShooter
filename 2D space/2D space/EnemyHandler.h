#ifndef INCLUDED_ENEMYHANDLER
#define INCLUDED_ENEMYHANDLER

#include "GameObject.h"
#include "Enemy.h"
#include "EnemyBullet.h"
#include "random.h"
#include "Timer.h"
#include <vector>

class EnemyHandler {
public:
	static EnemyHandler * instance();
	
	void addEnemy(GameObject *enemy);
	void addEnemyBullet(GameObject *enemyBullet);
	void delEnemy();
	void delEnemyBullet();
	void draw();
	void update();
	void reset();

	typedef std::vector<GameObject*> Enemys;
	Enemys m_enemys;

	typedef std::vector<GameObject*> E_bullets;
	E_bullets m_bullets;

private:
	EnemyHandler();
	~EnemyHandler();
	bool timer();
	int _time = 660;

	Timer *_timer;
	static EnemyHandler * sm_instance;
};
#endif // !INCLUDED_ENEMYHANDLER
