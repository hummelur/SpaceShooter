#ifndef INCLUDED_ENEMYHANDLER
#define INLCUDED_ENEMYHANDLER

#include "Enemy.h"
#include "GameObject.h"
#include <vector>
class EnemyHandler {
public:
	static EnemyHandler * instance();

	EnemyHandler();
	~EnemyHandler();

	void addEnemy(GameObject *enemy);
	void delEnemy();
	void draw();
	void update();
	
private:
	typedef std::vector<GameObject*> Enemys;
	Enemys _enemys;
	static EnemyHandler * sm_instance;
};
#endif // !INCLUDED_ENEMYHANDLER