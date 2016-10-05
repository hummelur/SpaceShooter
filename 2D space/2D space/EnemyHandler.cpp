#include "EnemyHandler.h"
#include "Enemy.h"
#include "random.h"

EnemyHandler * EnemyHandler::sm_instance = new EnemyHandler();

EnemyHandler::EnemyHandler() {
}
EnemyHandler::~EnemyHandler() {
	
}
EnemyHandler * EnemyHandler::instance() {
	return sm_instance;
}

void EnemyHandler::addEnemy(GameObject *enemy) {
	//Logik f�r att l�gga till enemys h�r ? Anv�nd timer
	_enemys.push_back(enemy);
}

void EnemyHandler::delEnemy() {
	std::vector<GameObject*>::const_iterator it;

	// Loopar igenom vectorn f�r att hitta de som �r utanf�r banan
	for (it = _enemys.begin(); it != _enemys.end();) {
		if ((*it)->getPos().y > Game::instance()->getWindowHeight() - 50) {
			// Tarbort enemy
			delete * it;
			it = _enemys.erase(it);
		}
		else {
			it++;
		}
	}
}

void EnemyHandler::draw() {
	for (auto &enemy : _enemys) {
		enemy->draw();
	}
}

void EnemyHandler::update() {
	for (auto &enemy : _enemys) {
		enemy->update();
	}
	addEnemy(new Enemy(Random::instance()->getRandom(10, (Game::instance()->getWindowWidth() - 10))));
	delEnemy();
}