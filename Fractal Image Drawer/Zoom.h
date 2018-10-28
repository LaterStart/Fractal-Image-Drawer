#pragma once

struct Zoom {
	int x{};
	int y{};
	double scale{};

	Zoom(int x, int y, double scale) :
			x(x),
			y(y),
			scale(scale) {
	};
};
