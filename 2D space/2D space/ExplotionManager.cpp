#include "ExplotionManager.h"


ExplotionManager * ExplotionManager::sm_instance = new ExplotionManager();

ExplotionManager::ExplotionManager() {

	_timer = new Timer(100);
	_timer->start();
}

ExplotionManager::~ExplotionManager() {
	
}

ExplotionManager * ExplotionManager::instance() {
	return sm_instance;
}

void ExplotionManager::addExplotion(GameObject *explotion) {
	m_explotions.push_back(explotion);
}

void ExplotionManager::delExplotion() {
	std::vector<GameObject*>::const_iterator it;

	// Loopar igenom vectorn för att hitta de som är utanför banan
	for (it = m_explotions.begin(); it != m_explotions.end();) {
		if ((*it)->getWidth() > 100) {
			// Tarbort powerup
			delete * it;
			it = m_explotions.erase(it);
		} else {
			it++;
		}
	}
}

void ExplotionManager::update() {
	for (auto &explotion : m_explotions)
		explotion->update();

	delExplotion();
}

void ExplotionManager::draw() {
	for (auto &explotion : m_explotions)
		explotion->draw();
}