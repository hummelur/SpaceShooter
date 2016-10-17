#include "GUI.h"

GUI * GUI::sm_instance = new GUI();


GUI::GUI() :
	screen(NULL),
	font(NULL){
	color = { 255, 255, 255, 255 };
	
}

GUI * GUI::instance() {
	return sm_instance;
}

void GUI::init() {
	// Laddar in bilden
	auto surface = IMG_Load("images/hearts.png");
	//Sätter bilden till texturen
	_hearttexture = SDL_CreateTextureFromSurface(Game::instance()->getRenderer(), surface);
	// Laddar in bilden
	surface = IMG_Load("images/pupgui.png");
	//Sätter bilden till texturen
	_pupguiTexture = SDL_CreateTextureFromSurface(Game::instance()->getRenderer(), surface);
	// Frigör surface
	SDL_FreeSurface(surface);

}

void GUI::draw() { 

	if (GameState::instance()->getGameState() == "Game") {
		// Sätter storleken för text och bredd på den
		SDL_Rect location = { 10, 10, 200 , 30 };

		// Laddar fonten
		font = TTF_OpenFont("font/olltard.ttf", 60);

		// Tar textsträngen och inten för poäng och sätter den till 
		// en sträng
		std::string s = std::to_string(Player::instance()->getPoints());
		s = "Points: " + s;

		// Sätter texten till surface
		points = TTF_RenderText_Blended(font, s.c_str(), color);
		if (points == nullptr) {
			TTF_CloseFont(font);
		}

		texture = SDL_CreateTextureFromSurface(Game::instance()->getRenderer(), points);
		if (texture == nullptr) {
			printf("Fail");
		}

		// Skriver ut texturen som gjordes i init
		SDL_RenderCopy(Game::instance()->getRenderer(), texture, nullptr, &location);

		//Skriverut hjärttexturerna
		float xpos = Game::instance()->getWindowWidth() - 175;
		SDL_Rect heartrect = { xpos, 10, Player::instance()->getHealth(), 35 };
		SDL_Rect srcheartrect = { 0, 0, Player::instance()->getHealth(), 35 };
		SDL_RenderCopy(Game::instance()->getRenderer(), _hearttexture, &srcheartrect, &heartrect);
		// Kollar om powerup är aktiv
		if (Player::instance()->getPowerup()) {
			if (Player::instance()->getPowerUpTime() > 50) {
				SDL_Rect pupGuiRect = { Game::instance()->getWindowWidth() / 2 - 100, Game::instance()->getWindowHeight() - 40, Player::instance()->getPowerUpTime() / 2, 40 };
				SDL_Rect srcPupRect = { 0, 0, Player::instance()->getPowerUpTime() / 2, 200 };
				SDL_RenderCopy(Game::instance()->getRenderer(), _pupguiTexture, &srcPupRect, &pupGuiRect);
			}
		}


		SDL_FreeSurface(points);
		SDL_DestroyTexture(texture);
		TTF_CloseFont(font);

	} else if(GameState::instance()->getGameState() == "Start") {
		// Sätter storleken för text och bredd på den
		SDL_Rect location = {  150 , 50, 300 , 50 };

		// Laddar fonten
		font = TTF_OpenFont("font/olltard.ttf", 60);
		if (!font) {
			printf("Fontfail");
		}

		//text strängen för att starta spelet
		std::string startString = "Press space to start!";

		// Sätter texten till surface
		startSurface = TTF_RenderText_Blended(font, startString.c_str(), color);
		if (!startSurface) {
			printf("Fail surface");
		}

		starttexture = SDL_CreateTextureFromSurface(Game::instance()->getRenderer(), startSurface);
		if (!starttexture) {
			printf("Failstarttexture");
		}
		// Skriver ut texturen som gjordes i init
		SDL_RenderCopy(Game::instance()->getRenderer(), starttexture, nullptr, &location);

		SDL_FreeSurface(startSurface);
		SDL_DestroyTexture(starttexture);
		TTF_CloseFont(font);

	} else if (GameState::instance()->getGameState() == "Gameover") {
		// Sätter storleken för text och bredd på den
		SDL_Rect location = { 150 , 50, 300 , 50 };

		// Laddar fonten
		font = TTF_OpenFont("font/olltard.ttf", 60);
		if (!font) {
			printf("Fontfail");
		}

		//text strängen för att starta spelet
		std::string startString = "Better luck next time!";

		// Sätter texten till surface
		startSurface = TTF_RenderText_Blended(font, startString.c_str(), color);
		if (!startSurface) {
			printf("Fail surface");
		}

		_gameOverTexture = SDL_CreateTextureFromSurface(Game::instance()->getRenderer(), startSurface);
		
		// Skriver ut texturen som gjordes i init
		SDL_RenderCopy(Game::instance()->getRenderer(), _gameOverTexture, nullptr, &location);

		SDL_FreeSurface(startSurface);
		SDL_DestroyTexture(_gameOverTexture);
		TTF_CloseFont(font);

	}
}
