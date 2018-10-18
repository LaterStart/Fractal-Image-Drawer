#include <iostream>
#include "Bitmap.h"
using namespace std;

int main() {
	Bitmap bitmap(1920, 1080);
	bitmap.Write("test.bmp");

	return 0;
}