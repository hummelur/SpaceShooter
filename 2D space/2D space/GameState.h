#ifndef INCLUDED_GAMESTATE
#define INCLUDED_GAMESTATE

#include <string>

class GameState {
public:
	static GameState * instance();

	GameState();
	~GameState();
	void setGameState(std::string gameState);
	std::string getGameState() const;
private:
	std::string _gameState = "Start";

	static GameState * sm_instance;
};
#endif // !INCLUDED_GAMESTATE
