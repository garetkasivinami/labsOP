#include <math.h>
#include <stdio.h>
#include <stdarg.h>
#pragma once
// версія 1.0
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
		printf_s("Точка знаходиться на початку координат\n");
	}
	else if (x == 0) {
		printf_s("Точка належить координатній осі Y\n");
	}
	else if (y == 0) {
		printf_s("Точка належить координатній осі X\n");
	}
	else {
		printf_s("Точка не належить жодній координатній осі\n");
	}
}
void CheckPos3(struct vector3 targetVector) {
	double x = targetVector.x, y = targetVector.y, z = targetVector.z;
	if (x == 0 && y == 0 && z == 0) {
		printf_s("Точка знаходиться на початку координат\n");
	}
	else if (x == 0 && y == 0) {
		printf_s("Точка належить координатній осі Z\n");
	}
	else if (x == 0 && z == 0) {
		printf_s("Точка належить координатній осі Y\n");
	}
	else if (y == 0 && z == 0) {
		printf_s("Точка належить координатній осі X\n");
	}
	else {
		printf_s("Точка не належить жодній координатній осі\n");
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
#define M_E        2.71828182845904523536   // e
#define M_LOG2E    1.44269504088896340736   // log2(e)
#define M_LOG10E   0.434294481903251827651  // log10(e)
#define M_LN2      0.693147180559945309417  // ln(2)
#define M_LN10     2.30258509299404568402   // ln(10)
#define M_PI       3.14159265358979323846   // pi
#define M_PI_2     1.57079632679489661923   // pi/2
#define M_PI_4     0.785398163397448309616  // pi/4
#define M_1_PI     0.318309886183790671538  // 1/pi
#define M_2_PI     0.636619772367581343076  // 2/pi
#define M_2_SQRTPI 1.12837916709551257390   // 2/sqrt(pi)
#define M_SQRT2    1.41421356237309504880   // sqrt(2)
#define M_SQRT1_2  0.707106781186547524401  // 1/sqrt(2)
#endif