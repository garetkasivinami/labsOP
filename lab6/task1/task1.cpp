#include <stdio.h>
#include <Windows.h>
struct vector2
{
	double x, y;
};
void minTask2(double firstNumber, double secondNumber) {
	char non[] = "Точка не належить зафарбованій області\n";
	char yes[] = "Точка належить зафарбованій обіласті\n";
	vector2 point;
	point.x = firstNumber;
	point.y = secondNumber;
	printf_s("%lf %lf",firstNumber,secondNumber);
	if (point.x < 0 && point.y < 0 && point.y <= point.x + 1 || point.x >= 0 && point.y >= -point.x + 1 && point.y <= point.x + 1 && point.y >= 0) {
		printf_s(yes);
	}
	else {
		printf_s(non);
	}
}
void Task1();
void Task2();
int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	/*
	for (int x = -3; x <= 3; x++) {
		for (int y = -3; y <= 3; y++) {
			minTask2(x,y);
		}
	}
	*/
	while (1) {
		printf_s("Оберіть завдання (1 чи 2). 0 - вихід з програми\n");
		int operation = 0;
		scanf_s("%d", &operation);
		switch (operation)
		{
		case 0:
			return 0;
		case 1:
			Task1();
			break;
		case 2:
			Task2();
			break;
		default:
			break;
		}
	}
	return 0;
}
void Task1() {
	char non[] = "Точка не належить зафарбованій області\n";
	char yes[] = "Точка належить зафарбованій обіласті\n";
	vector2 point;
	printf_s("Введіть два числа(x,y) для перевірки\n");
	scanf_s("%lf %lf", &point.x, &point.y);
	if (point.x < 0 && point.y <= 0 && point.y <= point.x + 1 || point.x >= 0 && point.y >= -point.x + 1 && point.y <= point.x + 1 && point.y >= 0) {
		printf_s(yes);
	}
	else {
		printf_s(non);
	}
}
void Task2() {
	printf_s("Напишіть коефіцієнти a,b,c \n ax^2+bx+c=0\n");
	double a, b, c;
	scanf_s("%lf %lf %lf",&a,&b,&c);
	double Discriminant = b * b - 4 * a * c;
	(Discriminant > 0) ? printf_s("Рівняння має два корені\n") : (Discriminant == 0) ? printf_s("Рівняння має один корінь\n"): printf_s("Рівняння не має коренів\n");
}