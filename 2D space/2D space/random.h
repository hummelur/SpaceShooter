#ifndef INCLUDED_RANDOM
#define INCLUDED_RANDOM

#include <cstdlib>

class Random {
public:
	static Random * instance();
	Random();
	~Random();
	float getRandom(float x, float xt);
private:
	static Random * sm_instance;
};
#endif // !INCLUDED_RANDOM
