#pragma once
#include<iostream>
#include<math.h>

unsigned char* negateImage(unsigned char* img, int w, int h)
{
	unsigned char* result = new unsigned char[w*h];
	for (int y = 0; y < h; y++)
		for (int x = 0; x < w; x++)
			result[y*w + x] = 255 - img[y*w + x];
	return result;
}

unsigned char* binaryImage(unsigned char* img, int w, int h, int th) {
	unsigned char* result = new unsigned char[w * h];
	for (int y = 0; y < h; y++)
		for (int x = 0; x < w; x++) {
			if (img[y * w + x] >= th) result[y * w + x] = 255;
			else result[y * w + x] = 0;
		}
	return result;
}

unsigned char* brightImage(unsigned char* img, int w, int h, int th) {
	unsigned char* result = new unsigned char[w * h];
	int temp;
	for (int y = 0; y < h; y++)
		for (int x = 0; x < w; x++) {
			temp = img[y * w + x] + th;
			if (temp < 0) temp = 0;
			else if (temp > 255) temp = 255;
			result[y * w + x] = temp;
		}
	return result;
}

unsigned char* contrastImage(unsigned char* img, int w, int h, int a, int b, int gap) {
	unsigned char* result = new unsigned char[w * h];
	int image, temp;

	float sa = a - (gap / 2.0f),
		  sb = b - (gap / 2.0f);

	float m = sa / a,
		n = (sb - sa) / (b - a),
		p = (255 - sb) / (255 - b);

	for (int y = 0; y < h; y++)
		for (int x = 0; x < w; x++) {
			image = img[y * w + x];
			temp = 0;
			if (0 <= image && image <= a) temp = (int)(m * image);
			else if (a <= image && image <= b) temp = (int)(n * (image - a) + sa);
			else if (b <= image && image <= 255) temp = (int)(p * (image - b) + sb);
			result[y * w + x] = temp;
		}
	return result;
}

unsigned char* bitSliceImage(unsigned char* img, int w, int h, int bit) {
	unsigned char* result = new unsigned char[w * h];
	int temp;
	for (int y = 0; y < h; y++)
		for (int x = 0; x < w; x++) {
			temp = img[y * w + x];
			temp >> bit - 1;
			result[y * w + x] = (temp % 2) * 255;
		}
	return result;
}

unsigned char* compressContrastImage(unsigned char* img, int w, int h, int c) {
	unsigned char* result = new unsigned char[w * h];
	int temp;
	for (int y = 0; y < h; y++)
		for (int x = 0; x < w; x++) {
			temp = c * log(img[y * w + x] + 1);
			result[y * w + x] = temp % 256;
		}
	return result;
}

unsigned char* gammaImage(unsigned char* img, int w, int h, float c) {
	unsigned char* result = new unsigned char[w * h];
	int temp;
	for (int y = 0; y < h; y++)
		for (int x = 0; x < w; x++) {
			//std::cout << (int)pow(img[y * w + x], 1 / c) << " ";
			result[y * w + x] = 80 * (int)pow(img[y * w + x], 1 / c);
		}
	return result;
}