#ifndef INCLUDED_ENEMYHANDLER
#define INCLUDED_ENEMYHANDLER

#include "GameObject.h"
#include "Enemy.h"
#include "random.h"
#include <vector>

class EnemyHandler {
public:
	static EnemyHandler * instance();
	
	void addEnemy(GameObject *enemy);
	void delEnemy();
	void draw();
	void update();

	typedef std::vector<GameObject*> Enemys;
	Enemys m_enemys;

private:
	EnemyHandler();
	~EnemyHandler();
	bool timer();
	int _time = 360;

	static EnemyHandler * sm_instance;
};
#endif // !INCLUDED_ENEMYHANDLER
