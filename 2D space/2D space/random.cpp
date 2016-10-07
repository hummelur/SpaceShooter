#include "random.h"

Random * Random::sm_instance = new Random();

Random::Random() {

}

Random::~Random() {
}

Random * Random::instance() {
	return sm_instance;
}

float Random::getRandom(int x, int xm) {
	return rand() % xm + x;
}