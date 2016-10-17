#include "Timer.h"

// initerar timern
Timer::Timer(int stime){
	_reseted = true;
	_running = false;
	_beg = stime;
	_end = stime;
	start();
}

// Startar timern
void Timer::start() {
	_running = true;
}

// Stoppar och ställer om timern
void Timer::stop() {
	_beg = _end;
	_running = false;
}

// Ställer tillbaka timern
void Timer::reset() {
	_reseted = true;
	_beg = _end;
	start();
}

// Körs för varje update
bool Timer::isRunning() {
	if (!_running) {
		return false;
	} else if(_beg >= 0) {
		_beg--;
		_running = true;
	} else {
		isOver();
		stop();
	}
}

// Returnerar tiden som har gått
int Timer::getTime() {
	return _beg;
}

// Sätter att det är slut
bool Timer::isOver() {
	if (!_running)
		return true;
	else
		return false;
}
