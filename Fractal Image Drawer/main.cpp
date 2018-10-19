#include <iostream>
#include <math.h>
#include "Bitmap.h"
#include "Mangelbrot.h"
using namespace std;

int main() {
	const int WIDTH{ 800 };
	const int HEIGHT{ 600 };

	Bitmap bitmap{ WIDTH, HEIGHT };

	unique_ptr<int[]> histogram(new int[Mangelbrot::MAX_ITERATIONS]{});
	unique_ptr<int[]> fractal(new int[WIDTH*HEIGHT]{});

	for (int y{}; y < HEIGHT; y++) {
		for (int x{}; x < WIDTH; x++) {
			double xFractal((x - WIDTH / 2 - 200)*2.0 / HEIGHT);
			double yFractal((y - HEIGHT / 2)*2.0 / HEIGHT);

			int iterations = Mangelbrot::GetIterations(xFractal, yFractal);

			fractal[y * WIDTH + x] = iterations;

			if(iterations != Mangelbrot::MAX_ITERATIONS)
				histogram[iterations]++;			

		}
	}

	int total{};
	for (int i{}; i < Mangelbrot::MAX_ITERATIONS; i++) {
		total += histogram[i];
	}

	for (int y{}; y < HEIGHT; y++) {
		for (int x{}; x < WIDTH; x++) {

			uint8_t red{};
			uint8_t green{};
			uint8_t blue{};

			int iterations = fractal[y * WIDTH + x];

			if (iterations != Mangelbrot::MAX_ITERATIONS) {

				double hue{ 0.0 };

				for (int i{}; i <= iterations; i++)
					hue += static_cast<double>(histogram[i]) / total;

				red = static_cast<uint8_t>(pow(255, hue));
			}

			uint8_t color(static_cast<uint8_t>((256 * (static_cast<double>(iterations) / Mangelbrot::MAX_ITERATIONS))));

			bitmap.SetPixel(x, y, red, green, blue);
		}
	}

	bitmap.Write("test.bmp");

	return 0;
}