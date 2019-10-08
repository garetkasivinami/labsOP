#include "mymath.h"
#include <stdio.h>
#include <windows.h>

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	double x, y, z, result;
	printf_s("Введіть три числа для розрахунку через пробіл(x,y,z)\n");
	scanf_s("%lf %lf %lf", &x, &y, &z);
	double maxVal = maxDouble(3, x, y, z);
	double minVal = minDouble(3, x, y, z);
	printf_s("Мінімальне число %lf, максимальне число %lf\n", minVal, maxVal);
	result = (maxVal - pow(2, x) * pow(minVal, 2)) / (sin(2 * x) + maxVal * pow(minVal, 2));
	printf_s("Результат: %lf\n", result);
}