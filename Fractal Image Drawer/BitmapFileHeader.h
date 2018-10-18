#pragma once
#include <cstdint>

#pragma pack(2)
struct BitmapFileHeader {
	char header[2]{ 'B', 'M' };
	int32_t fileSize;
	int32_t reserved{};
	int32_t dataOffset;
};
