#include <stdio.h>
#include <windows.h>
double Calculate(double a, double b, double c, double d);
int main() 
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	double a, b, c, d;
	printf_s("а = ");
	scanf_s("%lf",&a);
	printf_s("b = ");
	scanf_s("%lf", &b);
	printf_s("c = ");
	scanf_s("%lf", &c);
	printf_s("d = ");
	scanf_s("%lf", &d);
	printf_s("Результат:%lf", Calculate(a,b,c,d));
	return 0;
}
double Calculate(double a, double b, double c, double d) {
	if (c == 0 || b == 0 || d == 0) {
		printf_s("Ділення на нуль заборонене");
		return 0;
	}
	return a / c - d / b - (a - c) / (c * d);
}