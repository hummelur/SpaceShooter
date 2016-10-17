#ifndef INCLUDED_GUI
#define INCLUDED_GUI

#include "game.h"
#include "SDL_ttf.h"
#include "SDL.h"
#include "SDL_image.h"
#include "GameState.h"
#include <string>

class GUI {
public:
	static GUI * instance();

	GUI();
	void init();
	void draw();
private:
	// Font and text vars
	TTF_Font *font; /*= TTF_OpenFont("CircleOfDust.ttf", 50);*/
	SDL_Surface *points; /*= TTF_RenderText_Solid(times, "Points: alibaba", color);*/
	SDL_Surface *startSurface;
	SDL_Color color = { 255, 255, 255, 255 };
	SDL_Surface *screen; //Tar m_window från game
	SDL_Surface *surface;

	SDL_Texture *texture;
	SDL_Texture *starttexture;
	SDL_Texture *_hearttexture;
	SDL_Texture *_pupguiTexture;
	SDL_Texture *_gameOverTexture;

	// Instance
	static GUI * sm_instance;
};
#endif // !INCLUDED_GUI
