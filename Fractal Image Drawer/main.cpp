#include <iostream>
#include "Bitmap.h"
#include "Mangelbrot.h"
using namespace std;

int main() {
	const int WIDTH{ 800 };
	const int HEIGHT{ 600 };

	Bitmap bitmap{ WIDTH, HEIGHT };

	for (int y{}; y < HEIGHT; y++) {
		for (int x{}; x < WIDTH; x++) {
			double xFractal((x - WIDTH / 2 - 200)*2.0 / HEIGHT);
			double yFractal((y - HEIGHT / 2)*2.0 / HEIGHT);

			int iterations = Mangelbrot::GetIterations(xFractal, yFractal);

			uint8_t color(static_cast<uint8_t>((256* (static_cast<double>(iterations) / Mangelbrot::MAX_ITERATIONS))));

			bitmap.SetPixel(x, y, color, 0, 0);

		}
	}

	bitmap.Write("test.bmp");

	return 0;
}