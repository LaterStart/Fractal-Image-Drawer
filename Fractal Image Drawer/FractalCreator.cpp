#include <string>
#include "FractalCreator.h"
#include "Mangelbrot.h"
using namespace std;

FractalCreator::FractalCreator(int width, int height) : 
		width(width),
		height(height),
		histogram(new int[Mangelbrot::MAX_ITERATIONS]{}),
		fractal(new int[width*height]{}),
		bitmap( width, height),
		zoomList(width, height) {
	zoomList.Add(Zoom(width / 2, height / 2, 4.0 / width));
}

void FractalCreator::Run(string name) {
	AddZoom(Zoom(295, height - 202, 0.1));
	AddZoom(Zoom(312, height - 304, 0.1));
	CalculateIteration();
	CalculateTotalIterations();
	DrawFractal();
	WriteBitmap(name);
}

void FractalCreator::CalculateIteration() {
	for (int y{}; y < height; y++) {
		for (int x{}; x < width; x++) {
			pair<double, double> coords{ zoomList.DoZoom(x, y) };

			int iterations{ Mangelbrot::GetIterations(coords.first, coords.second) };

			fractal[y * width + x] = iterations;

			if (iterations != Mangelbrot::MAX_ITERATIONS)
				histogram[iterations]++;

		}
	}
}

void FractalCreator::CalculateTotalIterations() {
	for (int i{}; i < Mangelbrot::MAX_ITERATIONS; i++)
		total += histogram[i];
}

void FractalCreator::DrawFractal() {
	for (int y{}; y < height; y++) {
		for (int x{}; x < width; x++) {

			uint8_t red{};
			uint8_t green{};
			uint8_t blue{};

			int iterations{ fractal[y * width + x] };

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
}
void FractalCreator::AddZoom(const Zoom& zoom) {
	zoomList.Add(zoom);
}
void FractalCreator::WriteBitmap(string name) {
	bitmap.Write(name);
}