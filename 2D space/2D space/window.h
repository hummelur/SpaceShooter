#ifndef INCLUDED_WINDOW
#define INCLUDED_WINDOW

#include <string>
#include "SDL.h"

class Window {
public:
	Window(const std::string &title, int width, int height); //Constructor som tar title width och height
	~Window(); //Destructor

	void pollEvents(); //Letar efter events tex att krysset trycks in
	void clear() const; //ritar ut saker p� sk�rmen s� som bakgrund 
						//DETTA SKALL BARA HA BAKGRUNDEN F�R SPELET INGET ANNAT

	inline bool isClosed() const { return _closed; } //returnerar att f�nstret �r st�ngt 

public:
	SDL_Window *_window = nullptr;
	SDL_Renderer *_renderer = nullptr;

private:
	bool init(); //H�r ska jag initera window

private:
	std::string _title; //String title of window
	int _width = 800; //Width of the window
	int _height = 600; //Height of the window

	bool _closed = false;
};

#endif // !INCLUDED_WINDOW