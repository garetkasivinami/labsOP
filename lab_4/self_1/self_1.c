#include <stdio.h>
#include <windows.h>
#include "mymath.h"

double calculateFunction(double x, double k);
int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	double R, k1, k2;
	printf_s("Формула кола x^2+y^2=R\n");
	printf_s("Формула першої прямої y = x*k1\n");
	printf_s("Формула другої прямої y = x*k2\n");
	printf_s("Введіть радіус кола\n");
	scanf_s("%lf",&R);
	printf_s("Кутовий коефіцієнт першої прямої(додатний)\n");
	scanf_s("%lf", &k1);
	printf_s("Введіть кутовий коефіцієнт другої прямої(відємний)\n");
	scanf_s("%lf", &k2);
	printf_s("Введіть координати точки через пробіл\n");
	struct vector2 point;
	struct vector2 zeroVector = createZeroVector();
	printf_s("Введіть позиції(2 шт.) точки через пробіл\n");
	scanf_s("%lf %lf", &point.x, &point.y);
	if (Distanse2(zeroVector, point) < R && ((point.x < 0) ? (point.y < calculateFunction(point.x, k1) || point.y > calculateFunction(point.x, k2)) : 1) ) {
		printf_s("Точка належить зафірбованій області!");
	}
	else {
		printf_s("Точка не належить зафірбованій області!\n");
	}
	printf_s("%lf",Distanse2(zeroVector, point));
	return 0;
}
double calculateFunction(double x, double k) {
	return x * k;
}