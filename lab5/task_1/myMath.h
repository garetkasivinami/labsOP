#include <math.h>
#include <stdio.h>
#include <stdarg.h>
#pragma once
#pragma region Вектори
struct vector2
{
	double x, y;
}; 
struct vector3
{
	double x, y, z;
};
struct vector2 createZeroVector() {
	struct vector2 vector;
	vector.x = 0, vector.y = 0;
	return vector;
}
double Distanse2(struct vector2 first, struct vector2 second) {
	return sqrt(pow(second.x - first.x,2) + pow(second.y - first.y,2));
}
double Distanse3(struct vector3 first, struct vector3 second) {
	return sqrt(pow(second.x - first.x, 2) + pow(second.y - first.y, 2) + pow(second.z - first.z,2));
}
void CheckPos2(struct vector2 targetVector) {
	double x = targetVector.x, y = targetVector.y;
	if (x == 0 && y == 0) {
		printf_s("Точка знаходиться на початку координат");
	}
	else if (x == 0) {
		printf_s("Точка належить координатній осі Y");
	}
	else if (y == 0) {
		printf_s("Точка належить координатній осі X");
	}
	else {
		printf_s("Точка не належить жодній координатній осі");
	}
}
void CheckPos3(struct vector3 targetVector) {
	double x = targetVector.x, y = targetVector.y, z = targetVector.z;
	if (x == 0 && y == 0 && z == 0) {
		printf_s("Точка знаходиться на початку координат");
	}
	else if (x == 0 && y == 0) {
		printf_s("Точка належить координатній осі Z");
	}
	else if (x == 0 && z == 0) {
		printf_s("Точка належить координатній осі Y");
	}
	else if (y == 0 && z == 0) {
		printf_s("Точка належить координатній осі X");
	}
	else {
		printf_s("Точка не належить жодній координатній осі");
	}
}
#pragma endregion
#pragma region Мінімальні значення
double minDouble(int count, ...) {
	double number;
	va_list valist;
	va_start(valist, count);
	double minval = va_arg(valist, double);
	for (int i = 1; i < count; i++) {
		number = va_arg(valist, double);
		if (number < minval) {
			minval = number;
		}
	}
	va_end(valist);
	return minval;
}
int minInt(int count, ...) {
	int number;
	va_list valist;
	va_start(valist, count);
	int minval = va_arg(valist, int);
	for (int i = 1; i < count; i++) {
		number = va_arg(valist, int);
		if (number < minval) {
			minval = number;
		}
	}
	va_end(valist);
	return minval;
}
float minFloat(int count, ...) {
	float number;
	va_list valist;
	va_start(valist, count);
	float minval = va_arg(valist, float);
	for (int i = 1; i < count; i++) {
		number = va_arg(valist, float);
		if (number < minval) {
			minval = number;
		}
	}
	va_end(valist);
	return minval;
}
#pragma endregion
#pragma region Максимальні значення
double maxDouble(int count, ...) {
	double number;
	va_list valist;
	va_start(valist, count);
	double maxval = va_arg(valist, double);
	for (int i = 1; i < count; i++) {
		number = va_arg(valist, double);
		if (number > maxval) {
			maxval = number;
		}
	}
	va_end(valist);
	return maxval;
}
int maxInt(int count, ...) {
	int number;
	va_list valist;
	va_start(valist, count);
	int maxval = va_arg(valist, int);
	for (int i = 1; i < count; i++) {
		number = va_arg(valist, int);
		if (number > maxval) {
			maxval = number;
		}
	}
	va_end(valist);
	return maxval;
}
float maxFloat(int count, ...) {
	float number;
	va_list valist;
	va_start(valist, count);
	float maxval = va_arg(valist, float);
	for (int i = 1; i < count; i++) {
		number = va_arg(valist, float);
		if (number > maxval) {
			maxval = number;
		}
	}
	va_end(valist);
	return maxval;
}
#pragma endregion
// математичні константи
#ifdef MathConst
#define _USE_MATH_DEFINES
#endif