#ifndef INCLUDED_GAME
#define INCLUDED_GAME

#include "SDL.h"
#include "player.h"

class Game {
public:

	static Game * instance(); // Gör en instance av game för att kunna kalla functioner 

	void update();
	bool init(const char* title, int w, int h);
	void render();
	void eventHandler(Player &player);
	inline bool isRunning()const { return m_running; }

	//get 
	SDL_Window* getWindow() const { return m_window; }
	SDL_Renderer* getRenderer() const { return m_renderer; }
	inline int getWindowWidth() const { return m_widthWin; }
	inline int getWindowHeight() const { return m_heightWin; }

private:
	Game();
	~Game();

	bool m_running = true;
	int m_widthWin, m_heightWin;

	SDL_Window *m_window;
	SDL_Renderer *m_renderer;

	Player player;

	static Game * sm_instance;
};
#endif // !INCLUDED_GAME
