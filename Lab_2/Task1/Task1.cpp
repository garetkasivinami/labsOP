#include <stdio.h>
#include <math.h>
#include <windows.h>
double Calculate(double x, double y, double z);
int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	double x, y, z;
	printf_s("x = ");
	scanf_s("%lf", &x);
	printf_s("y = ");
	scanf_s("%lf", &y);
	printf_s("z = ");
	scanf_s("%lf", &z);
	double result = Calculate(x,y,z);
	printf_s("Result = %lf\n",result);
	return 0;
}
double Calculate(double x, double y, double z) {
	double powX = pow(x, 2);
	double powZ = pow(z, 3);
	if (powX + powZ + 4== 0) {
		printf_s("Ділення на нуль заборонено оберіть інші коефіцієнти Х та Z\n");
		return 0;
	}
	return pow(3 + (x - y),1.0/3.0) / (powX + powZ + 4) - tan(z);
}