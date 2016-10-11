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

void BulletHandler::addBullet(GameObject *bullet) {
	// Pushar in ett nytt object till vectorn.
	m_bullets.push_back(bullet);
}

void BulletHandler::delBullet() { 
	std::vector<GameObject*>::const_iterator it;

	// Loopar igenom vectorn f�r att hitta de som �r utanf�r banan
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
	
	collisionHandlerBullet(EnemyHandler::instance()->m_enemys);

	//uppdaterar positionen f�r alla f�rem�l i vectorn
	for (auto &bullets : m_bullets) {
		bullets->update();
	}
	// Kolla om bulletsen kolliderar med n�got eller �r utanf�r banan
	//H�R
	delBullet();
}

void BulletHandler::collisionHandlerBullet(std::vector<GameObject*> &enemys) {
	bool deleteBullet = false;
	std::vector<GameObject*>::const_iterator it;
	std::vector<GameObject*>::const_iterator ite;

	//Loopar igenom b�da arraysen
	for (it = m_bullets.begin(); it != m_bullets.end();) {
		for (ite = enemys.begin(); ite != enemys.end();) {
			//kolla om de kolliderar
 			if (CollisionHandler::instance()->Collision((*ite)->getPos(), (*ite)->getWidth(), (*ite)->getHeight(),
				(*it)->getPos(), (*it)->getWidth(), (*it)->getHeight())) {
				Player::instance()->givePoints(10);
				delete * ite;
				ite = enemys.erase(ite);
				deleteBullet = true;
			} else {
				ite++;
			}
		}
		// Om de kolliderade skall bulleten ocks� tas bort 
		if (deleteBullet) {
			delete * it;
			it = m_bullets.erase(it);
			deleteBullet = false;
		} else {
			it++;
		}
	}

}


