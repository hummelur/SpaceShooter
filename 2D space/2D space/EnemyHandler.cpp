#include "EnemyHandler.h"

EnemyHandler * EnemyHandler::sm_instance = new EnemyHandler();

EnemyHandler::EnemyHandler()
{
	_timer = new Timer(100);
	_timer->start();

}

EnemyHandler::~EnemyHandler(){
	m_enemys.clear();
}

EnemyHandler * EnemyHandler::instance() {
	return sm_instance;
}

void EnemyHandler::reset() {
	m_enemys.clear();
}

void EnemyHandler::addEnemy(GameObject *enemy){
	m_enemys.push_back(enemy);
}

void EnemyHandler::addEnemyBullet(GameObject *enemyBullet) {
	m_bullets.push_back(enemyBullet);
}

void EnemyHandler::delEnemy() {
	std::vector<GameObject*>::const_iterator it;

	// Loopar igenom vectorn för att hitta de som är utanför banan
	for (it = m_enemys.begin(); it != m_enemys.end();) {
		if ((*it)->getPos().y > Game::instance()->getWindowHeight()) {
			// Tarbort bullet
			delete * it;
			it = m_enemys.erase(it);
		} else {
			it++;
		}
	}
}

void EnemyHandler::delEnemyBullet() {
	std::vector<GameObject*>::const_iterator it;

	// Loopar igenom vectorn för att hitta de som är utanför banan
	for (it = m_bullets.begin(); it != m_bullets.end();) {
		if ((*it)->getPos().y > Game::instance()->getWindowHeight()) {
			// Tarbort bullet
			delete * it;
			it = m_bullets.erase(it);
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
	for (auto &ebullet : m_bullets)
		ebullet->draw();
}

void EnemyHandler::update() {
	
	// Updaterar enemy
	for (auto &enemy : m_enemys) {
		enemy->update();
		
	}
	if (timer()) {
		addEnemy(new Enemy(Random::instance()->getRandom(10, Game::instance()->getWindowWidth() - 45)));
		// KOllar om spelarens poäng är större än de maximala antalet
		if (Player::instance()->getPoints() > 450) {
			// Återställer timern
			_time = 650 - 450;
		} else {
			// Återställer timern
			_time = 650 - Player::instance()->getPoints();
		}
	}
	delEnemy();
	delEnemyBullet();
	
	// Updaterar bullet
	for (auto &ebullet : m_bullets)
		ebullet->update();

}

bool EnemyHandler::timer() {
	_time -= 10;

	if (_time <= 0) {
		return true;
	} else {
		return false;
	}
}