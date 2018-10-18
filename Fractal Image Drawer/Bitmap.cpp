#include "Bitmap.h"
#include "BitmapInfoHeader.h"
#include "BitmapFileHeader.h"

Bitmap::Bitmap(int width, int height) : 
	width(width), height(height), pixels(new uint8_t[width*height * 3]{}) {
}

bool Bitmap::Write(std::string fileName) {
	return false;
}

void Bitmap::SetPixel(int x, int y, uint8_t r, uint8_t g, uint8_t b) {
}