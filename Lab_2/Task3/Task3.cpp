#include <stdio.h>
#include <math.h>
#include <windows.h>
void changeNumbers(int* first, int* second);
double SpecialDegreeConvertTo_0_360(double value);
int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	printf_s("Завдання 3.1\n");
	int a, b, c;
	printf_s("a = ");
	scanf_s("%d", &a);
	printf_s("b = ");
	scanf_s("%d", &b);
	printf_s("c = ");
	scanf_s("%d", &c);
	printf("Ваші числа:%d,%d,%d\n", a, b, c);
	printf("Зміна значень А та В\n");
	changeNumbers(&a,&b);
	printf_s("Ваші числа:%d,%d,%d\n", a, b, c);
	printf("Зміна значень В та С\n");
	changeNumbers(&b, &c);
	printf_s("Ваші числа:%d,%d,%d\n", a, b, c);
	printf("Зміна значень С та А\n");
	changeNumbers(&c, &a);
	printf_s("Ваші числа:%d,%d,%d\n", a, b, c);
	printf_s("Завдання 3.2\n");
	double degree;
	int exit = 1;
	while (exit) {
		printf_s("Введіть градус для конвертації в радіани\n");
		scanf_s("%lf", &degree);
		degree = SpecialDegreeConvertTo_0_360(degree) / 180.0 * 3.14159265358979;
		printf_s("Радіани:%lf\n Для продовження напишіть будь-яке ціле число відмінне від нуля\n", degree);
		scanf_s("%d", &exit);
	}
}
void changeNumbers(int* first, int* second) {
	*first += *second;
	*second = *first - *second;
	*first -= *second;
}
double SpecialDegreeConvertTo_0_360(double value) {
	int divideResult = (int)floor(value / 360.0);
	//if (value < 0) { divideResult = -divideResult; }
	return value - 360.0 * divideResult;
}