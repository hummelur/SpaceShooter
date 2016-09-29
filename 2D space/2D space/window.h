#ifndef INCLUDED_WINDOW
#define INCLUDED_WINDOW

#include <string>
#include "SDL.h"
class Window {
public:
	Window(const std::string &title, int width, int height);
	~Window();

	void pollEvents();
	void clear() const;

	inline bool isClosed() const { return _closed; }

private:
	bool init(); //Här ska jag initera window

private:
	std::string _title;
	int _width = 800;
	int _height = 600;

	bool _closed = false;

	SDL_Window *_window = nullptr;
	SDL_Renderer *_renderer = nullptr;
};
#endif // !INCLUDED_WINDOW