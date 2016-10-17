#include "BulletHandler.h"
#include <windows.h>

BulletHandler * BulletHandler::sm_instance = new BulletHandler();

BulletHandler::BulletHandler(){
}

BulletHandler::~BulletHandler() {
	// Tarbort bullets
	m_bullets.clear();
	
}

BulletHandler * BulletHandler::instance() {
	return sm_instance;
}

void BulletHandler::reset() {
	m_bullets.clear();
}

void BulletHandler::addBullet(GameObject *bullet) {
	// Pushar in ett nytt object till vectorn.
	m_bullets.push_back(bullet);
}

void BulletHandler::delBullet() { 
	std::vector<GameObject*>::const_iterator it;

	// Loopar igenom vectorn för att hitta de som är utanför banan
	for (it = m_bullets.begin(); it != m_bullets.end();) {
		if ((*it)->getPos().y < 10) {
			// Tarbort bullet
			delete * it;
			it = m_bullets.erase(it);
		} else {
			it++;
		}
	}
	
}


void BulletHandler::draw() {
	// ritar ut allt i vectorn
	for (auto &bullets : m_bullets) {
		bullets->draw();
	}
}

void BulletHandler::update() {
	
	//collisionHandlerBullet(EnemyHandler::instance()->m_enemys);

	//uppdaterar positionen för alla föremål i vectorn
	for (auto &bullets : m_bullets) {
		bullets->update();
	}
	// Kolla om bulletsen kolliderar med något eller är utanför banan
	//HÄR
	delBullet();
}


