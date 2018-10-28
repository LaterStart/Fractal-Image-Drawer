#pragma once

class Mangelbrot {
public:
	Mangelbrot() = default;
	virtual ~Mangelbrot() = default;

public:
	static int GetIterations(double x, double y);

public:
	static const int MAX_ITERATIONS{ 1000 };
};

