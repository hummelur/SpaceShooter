#include "GameState.h"

GameState * GameState::sm_instance = new GameState();

GameState::GameState():
	_gameState("Start"){
 	_gameState = "Start";
}

GameState::~GameState(){}

GameState * GameState::instance() {
	return sm_instance;
}

void GameState::setGameState(std::string gameState) {
	_gameState = gameState;
}

std::string GameState::getGameState() const {
	return _gameState;
}