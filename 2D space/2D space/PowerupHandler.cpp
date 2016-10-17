#include "PowerupHandler.h"

PowerupHandler * PowerupHandler::sm_instance = new PowerupHandler();

PowerupHandler::PowerupHandler(){
	_timer = new Timer(1500);
	_timer->start();
}

PowerupHandler::~PowerupHandler() {
	m_powerups.clear();
}

PowerupHandler * PowerupHandler::instance() {
	return sm_instance;
}

void PowerupHandler::reset() {
	m_powerups.clear();
}

void PowerupHandler::addPowerup(GameObject *powerup) {
	m_powerups.push_back(powerup);
}

void PowerupHandler::delPowerup() {
	std::vector<GameObject*>::const_iterator it;

	// Loopar igenom vectorn för att hitta de som är utanför banan
	for (it = m_powerups.begin(); it != m_powerups.end();) {
		if ((*it)->getPos().y > Game::instance()->getWindowHeight()) {
			// Tarbort powerup
			delete * it;
			it = m_powerups.erase(it);
		}
		else {
			it++;
		}
	}
}

void PowerupHandler::draw() {
	for (auto &pup : m_powerups)
		pup->draw();
}

void PowerupHandler::update(){
	for (auto &pup : m_powerups)
		pup->update();

	if (!_timer->isOver()) {
		_timer->isRunning();
	} else {
		addPowerup(new Powerup());
		_timer->reset();
	}
	delPowerup();
}