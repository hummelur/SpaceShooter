#include "game.h"
#include "player.h"
#include "Bullet.h"
#include "BulletHandler.h"
#include "EnemyHandler.h"

Game * Game::sm_instance = new Game();

Game::Game():
	m_widthWin(0),
	m_heightWin(0),
	m_running(false){
}
Game::~Game(){}

Game * Game::instance() {
	return sm_instance;
}

bool Game::init(const char* title, int w, int h) {
	
	//Inits sdl video
	SDL_Init(SDL_INIT_VIDEO);

	//sets the playingfield width and height
	m_widthWin = w;
	m_heightWin = h;

	// S�tter f�nstret till en variabel
	m_window = SDL_CreateWindow(
		title, 
		SDL_WINDOWPOS_UNDEFINED, 
		SDL_WINDOWPOS_UNDEFINED,
		w, h, 
		0
	);

	// S�tter upp en renderer
	m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_PRESENTVSYNC);
	
	// S�tter att programmet k�rs till true
	m_running = true;

	//S�tter spelarens startposition
	player.setPosY(m_heightWin - 100);
	player.setPosX((m_widthWin / 2) - player.getWidth());

	//Skapa 20 enemys
	for (int i = 0; i < 20; i++) {
		EnemyHandler::instance()->addEnemy(new Enemy(400));
	}

	return true;
}

void Game::update() {
	// Uppdaterar spelaren
	player.update();
	BulletHandler::instance()->update();
	EnemyHandler::instance()->update();

	// K�r eventhandlern
	eventHandler(player);
}

void Game::render() {
	// S�tter backgrundsf�rgen
	SDL_SetRenderDrawColor(m_renderer, 0, 0, 0, 255);
	// Clearar ut det p� sk�rmen
	SDL_RenderClear(m_renderer);

	// H�R IMELLAN SKA ALLT RENDERAS
	BulletHandler::instance()->draw();
	EnemyHandler::instance()->draw();
	player.draw();
	
	// Pressenterar det till f�nstret
	SDL_RenderPresent(m_renderer);
}

void Game::eventHandler(Player &player) {
	// Skapar ett event f�r att kunna k�ra ett poll event endast
	SDL_Event event;
	


	if (SDL_PollEvent(&event)) {
	
		player.eventHandler(event);

		switch (event.type)
		{
			case SDL_QUIT:
				m_running = false;
				break;
			default:
				break;
		}
		switch (event.key.keysym.sym) {
		case SDLK_ESCAPE:
			m_running = false;
			break;
		default:
			break;
		}
	}	
}