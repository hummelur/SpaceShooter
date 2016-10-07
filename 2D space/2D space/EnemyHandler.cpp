#include "EnemyHandler.h"

EnemyHandler * EnemyHandler::sm_instance = new EnemyHandler();

EnemyHandler::EnemyHandler(){}

EnemyHandler::~EnemyHandler(){
	m_enemys.clear();
}

EnemyHandler * EnemyHandler::instance() {
	return sm_instance;
}

void EnemyHandler::addEnemy(GameObject *enemy){
	m_enemys.push_back(enemy);
}

void EnemyHandler::delEnemy() {
	std::vector<GameObject*>::const_iterator it;

	// Loopar igenom vectorn för att hitta de som är utanför banan
	for (it = m_enemys.begin(); it != m_enemys.end();) {
		if ((*it)->getPos().y > Game::instance()->getWindowHeight()) {
			// Tarbort bullet
			delete * it;
			it = m_enemys.erase(it);
		}
		else {
			it++;
		}
	}
}

void EnemyHandler::draw() {
	// Ritar ut alla bullet object
	for (auto &enemy : m_enemys) {
		enemy->draw();
	}
}

void EnemyHandler::update() {
	// Updaterar enemy
	for (auto &enemy : m_enemys) {
		enemy->update();
	}
	if (timer()) {
		addEnemy(new Enemy(Random::instance()->getRandom(10, Game::instance()->getWindowWidth() - 45)));
		_time = 360;
	}
	// Gör en timer för att spawna de olika enemysen	
	delEnemy();
}

bool EnemyHandler::timer() {
	_time -= 10;

	if (_time <= 0) {
		return true;
	} else {
		return false;
	}
}