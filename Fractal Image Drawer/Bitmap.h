#pragma once
#include <string>
#include <cstdint>

class Bitmap {
public:
	Bitmap(int width, int height);
	virtual ~Bitmap() = default;

public:
	bool Write(std::string fileName);
	void SetPixel(int x, int y, uint8_t r, uint8_t g, uint8_t b);

private:
	int width{};
	int height{};
	std::unique_ptr<uint8_t[]> pixels{ nullptr };
};

