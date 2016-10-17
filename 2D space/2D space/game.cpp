#include "game.h"


Game * Game::sm_instance = new Game();

Game::Game():
	m_widthWin(0),
	m_heightWin(0),
	m_running(false){
}
Game::~Game(){
	SDL_DestroyRenderer(m_renderer);
	SDL_DestroyWindow(m_window);
	SDL_Quit();
}

Game * Game::instance() {
	return sm_instance;
}

bool Game::init(const char* title, int w, int h) {
	
	//Inits sdl video
	SDL_Init(SDL_INIT_VIDEO);

	// Inits SDL image
	if (IMG_Init(IMG_INIT_PNG) != 2) {
		printf(IMG_GetError());
	}

	// Inits SDL ttf (text)
	if (!TTF_Init()) {
		printf(TTF_GetError());
	}

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

	//Gör skärmen för att rendera text
	m_screen = SDL_GetWindowSurface(m_window);

	// Sätter upp en renderer
	m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_PRESENTVSYNC);
	
	// Sätter att programmet körs till true
	m_running = true;

	//Sätter spelarens startposition och textur
	Player::instance()->setTexture();
	Player::instance()->setPosY(m_heightWin - 100);
	Player::instance()->setPosX((m_widthWin / 2) - Player::instance()->getWidth());

	// Init GUI
	GUI::instance()->init();


	return true;
}

void Game::update() {
	if (GameState::instance()->getGameState() == "Game") {
		// Uppdaterar spelaren
		Player::instance()->update();
		BulletHandler::instance()->update();
		EnemyHandler::instance()->update();
		PowerupHandler::instance()->update();
		ExplotionManager::instance()->update();
		CollisionHandler::instance()->CheckObjCollision();
	}

	// Kör eventhandlern
	eventHandler();
}

void Game::render() {
	// Sätter backgrundsfärgen
	SDL_SetRenderDrawColor(m_renderer, 0, 0, 0, 255);
	// Clearar ut det på skärmen
	SDL_RenderClear(m_renderer);
	
	if (GameState::instance()->getGameState() == "Game") {
		// HÄR IMELLAN SKA ALLT RENDERAS
		BulletHandler::instance()->draw();
		EnemyHandler::instance()->draw();
		PowerupHandler::instance()->draw();
		Player::instance()->draw();
		ExplotionManager::instance()->draw();
		GUI::instance()->draw();
	} else {
		GUI::instance()->draw();
	}

	// Pressenterar det till fönstret
	SDL_RenderPresent(m_renderer);
}

void Game::eventHandler() {
	// Skapar ett event för att kunna köra ett poll event endast
	SDL_Event event;
	
	// Lyssnar efter events
	if (SDL_PollEvent(&event)) {
		// Om gamestate är game så körs detta
		if (GameState::instance()->getGameState() == "Game") {
			//Kallar på spelarens eventhandler
			Player::instance()->eventHandler(event);
		}
		//Lyssnar efter events
		switch (event.type)
		{
			case SDL_QUIT:
				m_running = false;
				break;
			default:
				break;
		} 
		if (GameState::instance()->getGameState() != "Game" && GameState::instance()->getGameState() != "Gameover") {
			switch (event.key.keysym.sym) {
				case SDLK_SPACE:
					GameState::instance()->setGameState("Game");
					break;
				default:
					break;
			}
		} else {
			switch (event.key.keysym.sym) {
				case SDLK_ESCAPE:
					m_running = false;
					break;
				default:
					break;
			}
		}
	}	
}