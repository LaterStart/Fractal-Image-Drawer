#include <fstream>
#include "Bitmap.h"
#include "BitmapInfoHeader.h"
#include "BitmapFileHeader.h"
using namespace std;

Bitmap::Bitmap(int width, int height) : 
	width(width), height(height), pixels(new uint8_t[width*height * 3]{}) {
}

bool Bitmap::Write(std::string fileName) {
	BitmapFileHeader fileHeader;
	BitmapInfoHeader infoHeader;

	fileHeader.fileSize = sizeof(BitmapFileHeader) + sizeof(BitmapInfoHeader) + width * height * 3;
	fileHeader.dataOffset = sizeof(fileHeader) + sizeof(infoHeader);

	infoHeader.width = width;
	infoHeader.height = height;

	ofstream file;
	file.open(fileName, ios::binary);
	if (file.is_open()) {
		file.write(reinterpret_cast<char*>(&fileHeader), sizeof(fileHeader));
		file.write(reinterpret_cast<char*>(&infoHeader), sizeof(infoHeader));
		file.write(reinterpret_cast<char*>(pixels.get()), width*height * 3);

		file.close();
	}
	else return false;

	return true;
}

void Bitmap::SetPixel(int x, int y, uint8_t r, uint8_t g, uint8_t b) {
	uint8_t* pixel = pixels.get();

	pixel += (y * 3) * width + (x * 3);

	// bmp - little endian
	pixel[0] = b;
	pixel[1] = g;
	pixel[2] = r;
}