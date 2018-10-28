#pragma once
#include "Bitmap.h"
#include "ZoomList.h"

class FractalCreator {
public:
	FractalCreator(int width, int height);
	virtual ~FractalCreator() = default;

private:
	void CalculateIteration();
	void CalculateTotalIterations();
	void DrawFractal();
	void AddZoom(const Zoom& zoom);
	void WriteBitmap(std::string name);

public:
	void Run(std::string name);

private:
	int width;
	int height;
	int total{};
	std::unique_ptr<int[]> histogram;
	std::unique_ptr<int[]> fractal;
	Bitmap bitmap;
	ZoomList zoomList;
};

