#include <complex>
#include "Mangelbrot.h"
using namespace std;

int Mangelbrot::GetIterations(double x, double y) {
	complex<double> z = 0;
	complex<double> c(x, y);

	int iterations{};

	while (iterations < MAX_ITERATIONS) {
		z = z * z + c;

		if (abs(z) > 2) {
			break;
		}

		iterations++;
	}

	return iterations;
}
