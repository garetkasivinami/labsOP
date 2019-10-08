#include<stdio.h>
#include<math.h>
#include<windows.h>
void PrintErrror();
int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	printf_s("ax^2+bx+c=0\n напишіть коефіцієнти\n");
	double a, b, c, x1, x2;
	printf_s("a = ");
	scanf_s("%lf", &a);
	printf_s("b = ");
	scanf_s("%lf", &b);
	printf_s("c = ");
	scanf_s("%lf", &c);
	if (a == 0) {
		PrintErrror();
	}
	double discriminant = pow(b,2) - 4 * a * c;
	printf_s("Дискримінант: %lf\n", discriminant);
	if (discriminant == 0) {
		x1 = -b / (a * 2);
		printf_s("Рівняння має один корінь: %lf\n",x1);
	}
	else if (discriminant > 0) {
		x1 = (-b - sqrt(discriminant)) / (2 * a);
		x2 = (-b + sqrt(discriminant)) / (2 * a);
		printf_s("Рівняння має два корені: %lf,%lf\n", x1, x2);
	}
	else {
		printf_s("Рівняння не має коренів\n");
	}
}
void PrintErrror() {
	printf_s("це не квадратне рівняння");
}