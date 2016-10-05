#include "random.h"

Random * Random::sm_instance = new Random();

Random::Random() {

}

Random::~Random() {
}

Random * Random::instance() {
	return sm_instance;
}

float Random::getRandom(float x, float xm) {
	float rslt;
	float range = xm - x;
	rslt = range * ((float)rand()) / xm + x;
	return rslt;
}