#pragma once
#include<iostream>
#include<math.h>

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

int* getHistogram(unsigned char * img, int w, int h, int size) {
	int* result = new int[size];
	int temp;

	for (int i = 0; i < size; i++) {
		result[i] = 0;
	}

	for (int y = 0; y < h; y++) {
		for (int x = 0; x < w; x++) {
			temp = img[y * w + x];
			if (temp >= 0 && temp <= size - 1) result[temp]++;
		}
	}
	return result;
}

unsigned char* equalize(unsigned char* img, int w, int h) {
	unsigned char* result = new unsigned char[w * h];
	float* H, * g;
	int size = 256;

	H = new float[size];
	g = new float[size];

	int* histogram = getHistogram(img, w, h, size);

	for (int i = 0; i < size; i++) {
		H[i] = (float)histogram[i] / (float)(w * h);
	}

	g[0] = H[0];

	for (int i = 1; i < size; i++) {
		g[i] = g[i - 1] + H[i];
	}

	for (int y = 0; y < h; y++)
		for (int x = 0; x < w; x++)
			result[y * w + x] = floor(255 * g[img[y * w + x]]);

	return result;
}