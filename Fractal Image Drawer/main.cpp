#include <iostream>
#include <math.h>
#include "Bitmap.h"
#include "Mangelbrot.h"
#include "ZoomList.h"
using namespace std;

int main() {
	const int WIDTH{ 800 };
	const int HEIGHT{ 600 };

	Bitmap bitmap{ WIDTH, HEIGHT };

	ZoomList zoomList(WIDTH, HEIGHT);
	zoomList.Add(Zoom(WIDTH / 2, HEIGHT / 2, 4.0 / WIDTH));
	zoomList.Add(Zoom(295, HEIGHT - 202, 0.1));
	zoomList.Add(Zoom(312, HEIGHT - 304, 0.1));

	unique_ptr<int[]> histogram(new int[Mangelbrot::MAX_ITERATIONS]{});
	unique_ptr<int[]> fractal(new int[WIDTH*HEIGHT]{});

	for (int y{}; y < HEIGHT; y++) {
		for (int x{}; x < WIDTH; x++) {
			pair<double, double> coords = zoomList.DoZoom(x, y);

			int iterations = Mangelbrot::GetIterations(coords.first, coords.second);

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