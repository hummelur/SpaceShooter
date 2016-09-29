#include "window.h"

int main(int argc, char* args[]) {

	Window window("SDL test", 899, 600);

	while (window.isClosed() != true) {
		window.pollEvents();
		window.clear();
	}

	return 0;
}