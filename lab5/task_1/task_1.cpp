#define _USE_MATH_DEFINES
#include <stdio.h>
#include <Windows.h>
#include "mymath.h"
#pragma region Коло
class Circle
{
public:
	Circle();
	~Circle();
	double radius = -1;
	double diameter = -1;
	double area = -1;
	double lenght = -1;
	void calculateStatsCircle(int data, double info);
	double calculateArea(double _radius);
private:

};
Circle::Circle()
{
}
Circle::~Circle()
{
}
void Circle::calculateStatsCircle(int data, double info) {
	switch (data)
	{
	case 1:
		radius = info;
		diameter = radius * 2;
		goto lenghtCal;
	case 2:
		diameter = info;
		radius = diameter / 2;
		goto lenghtCal;
	case 3:
		area = info;
		radius = sqrt(area / M_PI);
		diameter = radius * 2;
		lenght = 2 * radius * M_PI;
		break;
	case 4:
		lenght = info;
		radius = lenght / M_PI / 2;
		diameter = radius * 2;
		goto areaCal;
	}
lenghtCal:
	lenght = 2 * radius * M_PI;
areaCal:
	area = calculateArea(radius);
}
double Circle::calculateArea(double _radius) {
	return M_PI * pow(_radius,2);
}
#pragma endregion
#pragma region Програма
void Task_1();
void Task_2();
void Task_3();
void SimpleTask3();
double formula1(double x, double y, double Fx);
int main() {
	while (true)
	{
		SetConsoleCP(1251);
		SetConsoleOutputCP(1251);
		int userNumber;
		printf_s("Оберіть завдання\n 1 - завдання 1\n 2 - завдання 2\n 3 - самостійна\n 0 - вихід\n");
		scanf_s("%d",&userNumber);
		switch (userNumber)
		{
		case 0:
			return 0;
		case 1:
			Task_1();
			break;
		case 2:
			Task_2();
			break;
		case 3:
			printf_s("Простий(0) чи складний спосіб(інше число)?\n");
			int number;
			scanf_s("%d",&number);
			if (number == 0) {
				printf_s("Обрано простий спосіб\n");
				SimpleTask3();
			}
			else {
				printf_s("Обрано складний спосіб\n");
				Task_3();
			}
			break;
		default:
			printf_s("Цей варіант не доступний\n");
			break;
		}
	}
	return 0;
}
#pragma endregion
#pragma region Завдання 1
void Task_1() {
	while (1) {
		int operation;
		double first, second, result;
		printf_s("Оберіть тип операції!\n 1 - додавання\n 2 - віднімання\n 3 - множення\n 4 - ділення\n 0 - вихід\n");
		scanf_s("%d", &operation);
		if (operation == 0) {
			return;
		}
		printf_s("Напишіть два числа через пробіл!\n");
		scanf_s("%lf %lf",&first,&second);
		switch (operation)
		{
		case 1:
			result = first + second;
			break;
		case 2:
			result = first - second;
			break;
		case 3:
			result = first * second;
			break;
		case 4:
			if (second == 0) {
				printf_s("Ділення на нуль заборонене!\n");
				continue;
			}
			result = first / second;
			break;
		default:
			printf_s("Обрано неправильний номер!\n");
			continue;
		}
		printf_s("Результат %lf\n",result);
	}
}
#pragma endregion
#pragma region Завдання 2
void Task_2(){
	double x, y, a;
	while (1) {
		int formula;
		printf_s("Оберіть формулу:\n 1 - f(x) = sin(x)\n 2 - f(x) = x ^ 2\n f(x) = exp(x)\n 0 - вихід\n");
		scanf_s("%d", &formula);
		if (formula == 0) {
			return;
		}
		printf_s("Напишіть два числа через пробіл!\n");
		scanf_s("%lf %lf", &x, &y);
		double result;
		switch (formula)
		{
		case 1:
			result = sin(x);
			break;
		case 2:
			result = pow(x,2);
			break;
		case 3:
			result = exp(x);
			break;
		default:
			printf_s("Обрано неправильний номер!\n");
			continue;
		}
		result = formula1(x,y,result);
		printf_s("Результат %lf\n",result);
	}
}
double formula1(double x, double y, double Fx) {
	double res = x * y;
	if (0.5 < res && res < 10) {
		return exp(Fx - fabs(y));
	}
	else if (0.1 < res && res < 0.5) {
		return pow(fabs(Fx + y), 1.0 / 3.0);
	}
	else {
		return 2 * pow(Fx, 2);
	}
}
#pragma endregion
#pragma region Самостійна
char* rad = new char[17]{ "Радіус кола %lf\n" };
char* diam = new char[19]{ "Діаметер кола %lf\n" };
char* area = new char[16]{ "Площа кола %lf\n" };
char* leng = new char[18]{ "Довжина кола %lf\n" };
char* link[4] = {
		rad,
		diam,
		area,
		leng };
int number;
double info;
Circle circle;
double** linkData = new double* [4]{
	&circle.radius,
	&circle.diameter,
	&circle.area,
	&circle.lenght
};
void Task_3() {
	while (1) {
		printf_s("Знайти інформацію про коло через:\n 1 - радіус\n 2 - діаметер\n 3 - площу\n 4 - довжину\n 0 - вихід\n");
		scanf_s("%d", &number);
		if (number == 0) {
			printf_s("Вихід з циклу\n");
			return;
		}
		printf_s("Введіть інформацію\n");
		scanf_s("%lf", &info);
		if (info <= 0) {
			printf_s("Число повинно бути додатним та більше нуля\n");
			continue;
		}
		if (number > 0 && number < 5) {
			circle.calculateStatsCircle(number, info);
		}
		else {
			printf_s("Цей варіант не доступний\n");
			continue;
		}
		number--;
		for (int i = 0; i < 4; i++) {
			if (i != number) {
				printf_s(link[i],*linkData[i]);
			}
		}
	}
}

void SimpleTask3() {
	while (1) {
		printf_s("Введіть номер роботи\n");
		scanf_s("%d", &number);
		if (number == 0) {
			printf_s("Вихід з циклу\n");
			return;
		}
		printf_s("Введіть інформацію\n");
		scanf_s("%lf", &info);
		if (info <= 0) {
			printf_s("Число повинно бути додатнім та більше нуля\n");
			continue;
		}
		switch (number)
		{
		case 1:
			circle.calculateStatsCircle(number,info);
			printf_s("Діаметер %lf\nПлоща %lf\n Довжина %lf\n",circle.diameter,circle.area,circle.lenght);
			break;
		case 2:
			circle.calculateStatsCircle(number, info);
			printf_s("Радіус %lf\nПлоща %lf\n Довжина %lf\n", circle.radius, circle.area, circle.lenght);
			break;
		case 3:
			circle.calculateStatsCircle(number, info);
			printf_s("Радіус %lf\nДіаметер %lf\n Довжина %lf\n", circle.radius, circle.diameter, circle.lenght);
			break;
		case 4:
			circle.calculateStatsCircle(number, info);
			printf_s("Радіус%lf\nДіаметер %lf\n Площа %lf\n", circle.radius, circle.diameter, circle.area);
			break;
		default:
			printf_s("Цей варіант не доступний\n");
			break;
		}
	}
}
#pragma endregion