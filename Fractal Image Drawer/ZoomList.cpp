#include "ZoomList.h"

ZoomList::ZoomList(int width, int height) : width(width), height(height) {

}

void ZoomList::Add(const Zoom& zoom) {
	zooms.push_back(zoom);

	xCenter += (zoom.x - width / 2)*scale;
	yCenter += (zoom.y - height / 2)*scale;

	scale *= zoom.scale;
}

std::pair<double, double> ZoomList::DoZoom(int x, int y) {
	double xFractal = (x - width / 2)*scale + xCenter;
	double yFractal = (y - height / 2)*scale + yCenter;

	return std::pair<double, double>(xFractal, yFractal);
}

