#ifndef INCLUDED_GAME
#define INCLUDED_GAME


#include "SDL.h"
#include "SDL_image.h"
#include "SDL_ttf.h"
#include "GUI.h"
#include "player.h"
#include "PowerupHandler.h"
#include "BulletHandler.h"
#include "CollisionHandler.h"
#include "ExplotionManager.h"
#include "Bullet.h"
#include "EnemyHandler.h"
#include "GameState.h"


class Game {
public:

	static Game * instance(); // Gör en instance av game för att kunna kalla functioner 

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
	SDL_Surface *m_screen;

	GameState *_gameState;

	static Game * sm_instance;
};
#endif // !INCLUDED_GAME
