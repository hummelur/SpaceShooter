#ifndef INCLUDED_GAME
#define INCLUDED_GAME

#include "SDL.h"
#include "SDL_image.h"
#include "player.h"
#include "BulletHandler.h"
#include "CollisionHandler.h"
#include "Bullet.h"
#include "EnemyHandler.h"

class Game {
public:

	static Game * instance(); // G�r en instance av game f�r att kunna kalla functioner 

	bool init(const char* title, int w, int h);
	
	void eventHandler();
	inline bool isRunning()const { return m_running; }

	// Get 
	SDL_Window* getWindow() const { return m_window; }
	SDL_Renderer* getRenderer() const { return m_renderer; }
	inline int getWindowWidth() const { return m_widthWin; }
	inline int getWindowHeight() const { return m_heightWin; }
	
	void render();
	void update();


private:
	Game();
	~Game();

	bool m_running = true;
	int m_widthWin, m_heightWin;

	SDL_Window *m_window;
	SDL_Renderer *m_renderer;

	static Game * sm_instance;
};
#endif // !INCLUDED_GAME
