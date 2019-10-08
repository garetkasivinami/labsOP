#include <stdio.h>
#include <windows.h>

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	printf_s("a * a + b * b * b\n");
	printf_s("x1 * x2 + x2 * x3 + x3 * x1\n");
	printf_s("b * b - 4 * a * c\n");
	printf_s("1 - x * x\n");
	printf_s("c * (a * b) / (b * b)\n");
	printf_s("a * b * b / 2 + a * b * c\n");
	printf_s("a * b + a * b * b / 4\n");
	printf_s("1 / a + a / d\n");
	printf_s("1 / (a * b * b + (a - b))\n");
	printf_s("1 + (a - b * b) / (4 / (a * a * a))\n");
	printf_s("(1 + a * a * a * a + 2 * d) / (2 * a + 4 * a * d - d * d * d)\n");
	printf_s("((x + 1) - (x - 1)) / 2 * x\n");
	return 0;
}

/*
double firstVoid(double a, double b);
double secondVoid(double x1, double x2, double x3);
double thirdVoid(double a, double b, double c);
double Void4(double x1);
*/
/*
double firstVoid(double a, double b) {
	return pow(a,2) + pow(b,3);
}

double secondVoid(double x1, double x2, double x3) {
	return x1 * x2 + x2 * x3 + x3 * x1;
}

double thirdVoid(double a, double b, double c) {
	return pow (b,2) - 4 * a * c;
}

double Void4(double x1) {
	return 1 - pow(x1, 2);
}
*/