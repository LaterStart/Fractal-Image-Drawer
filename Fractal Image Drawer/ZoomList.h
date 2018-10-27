#pragma once
#include <vector>
#include <utility>
#include "Zoom.h"

class ZoomList {
private:
	double xCenter{};
	double yCenter{};
	double scale{1.0};
	int width{};
	int height{};
	std::vector<Zoom> zooms;

public:
	ZoomList(int width, int height);
	void Add(const Zoom& zoom);
	std::pair<double, double> DoZoom(int x, int y);
};

