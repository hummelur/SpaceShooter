#ifndef INCLUDED_TIMER
#define INCLUDED_TIMER

#include <iostream>
#include <time.h>
#include <conio.h>

class Timer {
public:

	Timer(int stime);
	void start();
	void stop();
	void reset();
	bool isRunning();
	int getTime();
	bool isOver();

private:
	bool _reseted;
	bool _running;
	int _beg;
	int _end;
};
#endif // !INCLUDED_TIMER
