#include "Timer.h"

Timer * Timer::sm_instance = new Timer();

Timer::Timer(){ }

Timer::~Timer(){}

bool Timer::Timr(int timeDown) {
	timeDown -= 10;

	if (timeDown <= 0) {
		return true;
	} else {
		return false;
	}
}
Timer * Timer::instance() {
	return sm_instance;
}