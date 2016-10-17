#include "CollisionHandler.h"

CollisionHandler * CollisionHandler::sm_instance = new CollisionHandler();

CollisionHandler::CollisionHandler(){}

CollisionHandler::~CollisionHandler(){}

CollisionHandler * CollisionHandler::instance() {
	return sm_instance;
}

bool CollisionHandler::Collision(const Vector2D posE, int we, int he,
								 const Vector2D posB, int wb, int hb) 
{
	return posE.x + we >= posB.x && posE.x <= posB.x + wb &&
		   posE.y + he >= posB.y && posE.y <= posB.y + hb;
}

void CollisionHandler::CheckObjCollision() {

	bool deleteBullet = false;

	std::vector<GameObject*> &_enemy = EnemyHandler::instance()->m_enemys;
	std::vector<GameObject*> &_bullet = BulletHandler::instance()->m_bullets;

	std::vector<GameObject*>::const_iterator it;
	std::vector<GameObject*>::const_iterator ite;

	//Loopar igenom båda arraysen
	for (it = _bullet.begin(); it != _bullet.end();) {
		for (ite = _enemy.begin(); ite != _enemy.end();) {
			//kolla om de kolliderar
			if (Collision((*ite)->getPos(), (*ite)->getWidth(), (*ite)->getHeight(),
				(*it)->getPos(), (*it)->getWidth(), (*it)->getHeight())) {
				Player::instance()->givePoints(5);
				ExplotionManager::instance()->addExplotion(new Explotion((*it)->getPos()));
				delete * ite;
				ite = _enemy.erase(ite);
				deleteBullet = true;
			} else {
				ite++;
			}
		}
		// Om de kolliderade skall bulleten också tas bort 
		if (deleteBullet) {
			delete * it;
			it = _bullet.erase(it);
			deleteBullet = false;
		}
		else {
			it++;
		}
	}

	//kollision mellan enemy och spelare
		for (ite = _enemy.begin(); ite != _enemy.end();) {
			//kolla om de kolliderar
			if (Collision(Player::instance()->getPos(), Player::instance()->getWidth(), Player::instance()->getHeight(),
				(*ite)->getPos(), (*ite)->getWidth(), (*ite)->getHeight())) {
				Player::instance()->setHealth(20);
				ExplotionManager::instance()->addExplotion(new Explotion((*ite)->getPos()));
				delete * ite;
				ite = _enemy.erase(ite);
			} else {
				ite++;
			}
		}

		//Kollision mellan spelare och enemybullets
		std::vector<GameObject*> &_enemyBullets = EnemyHandler::instance()->m_bullets;
		for (it = _enemyBullets.begin(); it != _enemyBullets.end();) {
			//kolla om de kolliderar
			if (Collision(Player::instance()->getPos(), Player::instance()->getWidth(), Player::instance()->getHeight(),
				(*it)->getPos(), (*it)->getWidth(), (*it)->getHeight())) {
				Player::instance()->setHealth(10);
				ExplotionManager::instance()->addExplotion(new Explotion(Player::instance()->getPos()));
				delete * it;
				it = _enemyBullets.erase(it);
			} else {
				it++;
			}
		}
		std::vector<GameObject*> &_pup = PowerupHandler::instance()->m_powerups;
		// Kollar efter kollision med powerups
		for (it = _pup.begin(); it != _pup.end();) {
			//kolla om de kolliderar
			if (Collision(Player::instance()->getPos(), Player::instance()->getWidth(), Player::instance()->getHeight(),
				(*it)->getPos(), (*it)->getWidth(), (*it)->getHeight())) {
				Player::instance()->setPowerup(true);
				delete * it;
				it = _pup.erase(it);
			} else {
				it++;
			}
		}
}
