#include <iostream>
#include "Bitmap.h"
using namespace std;

int main() {
	const int WIDTH = 1920;
	const int HEIGHT = 1080;

	Bitmap bitmap(WIDTH, HEIGHT);

	for (int y{}; y < HEIGHT; y++) {
		for (int x{}; x < WIDTH; x++) {
			bitmap.SetPixel(x, y, 255, 127, 80);
		}
	}

	bitmap.Write("test.bmp");

	return 0;
}