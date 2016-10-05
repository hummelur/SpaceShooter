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

	// Sätter fönstret till en variabel
	m_window = SDL_CreateWindow(
		title, 
		SDL_WINDOWPOS_UNDEFINED, 
		SDL_WINDOWPOS_UNDEFINED,
		w, h, 
		0
	);

	// Sätter upp en renderer
	m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_PRESENTVSYNC);
	
	// Sätter att programmet körs till true
	m_running = true;

	//Sätter spelarens startposition
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

	// Kör eventhandlern
	eventHandler(player);
}

void Game::render() {
	// Sätter backgrundsfärgen
	SDL_SetRenderDrawColor(m_renderer, 0, 0, 0, 255);
	// Clearar ut det på skärmen
	SDL_RenderClear(m_renderer);

	// HÄR IMELLAN SKA ALLT RENDERAS
	BulletHandler::instance()->draw();
	EnemyHandler::instance()->draw();
	player.draw();
	
	// Pressenterar det till fönstret
	SDL_RenderPresent(m_renderer);
}

void Game::eventHandler(Player &player) {
	// Skapar ett event för att kunna köra ett poll event endast
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