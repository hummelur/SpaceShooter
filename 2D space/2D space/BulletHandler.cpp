#include "BulletHandler.h"

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

void BulletHandler::addBullet(GameObject *bullet) {
	// Pushar in ett nytt object till vectorn.
	m_bullets.push_back(bullet);
}

void BulletHandler::delBullet() { 
	std::vector<GameObject*>::const_iterator it;

	// Loopar igenom vectorn f�r att hitta de som �r utanf�r banan
	for (it = m_bullets.begin(); it != m_bullets.end();) {
		if ((*it)->getPos().y < 200) {
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
	//uppdaterar positionen f�r alla f�rem�l i vectorn
	for (auto &bullets : m_bullets) {
		bullets->update();
	}
	// Kolla om bulletsen kolliderar med n�got eller �r utanf�r banan
	//H�R
	delBullet();
}