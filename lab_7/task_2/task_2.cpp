#include <stdio.h>
#include <Windows.h>
#include <math.h>
#pragma region Ідентифікатори
void Task_1W();
void Task_1F();
void Task_2W();
void Task_2F();
void Task_3W();
void Task_3F();
void Task_self_F();
void Task_self_W();
double formula1(double x);
double formula2(double x);
#pragma endregion
#pragma region Програма
int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int number, whileORfor;
	while (1) {
		printf_s("Оберіть завдання:\n 1 - Завдання 1\n 2 - Завдання 2\n 3 - Завдання 3\n 4 - Самостійна робота\n 0 - Вихід\n");
		scanf_s("%d", &number);
		if (number == 0) {
			return 0;
		}
		printf_s("Оберіть режим роботи:\n 0 - for\n інше число - while\n");
		scanf_s("%d", &whileORfor);
		switch (number)
		{
		case 1:
			if (whileORfor) {
				Task_1W();
			}
			else {
				Task_1F();
			}
			break;
		case 2:
			if (whileORfor) {
				Task_2W();
			}
			else {
				Task_2F();
			}
			break;
		case 3:
			if (whileORfor) {
				Task_3W();
			}
			else {
				Task_3F();
			}
			break;
		case 4:
			if (whileORfor) {
				Task_self_W();
			}
			else {
				Task_self_F();
			}
			break;
		default:
			continue;
		}
	}
	return 0;
}
#pragma endregion
#pragma region Завдання 1
void Task_1W()
{
	int count = 0, number = 1, sum = 0;
	while (count < 5) {
		if (number % 5 == 0) {
			count++;
			sum += number;
		}
		number++;
	}
	printf_s("Сума чисел: %d\n", sum);
}
void Task_1F()
{
	int count = 0, sum = 0;
	for (int number = 1; count < 5; number++) {
		if (number % 5 == 0) {
			count++;
			sum += number;
		}
	}
	printf_s("Сума чисел: %d\n", sum);
}
#pragma endregion
#pragma region Завдання 2
void Task_2W() {
	printf_s("Введіть максимальне число\n");
	int number, counter = 1;
	double result = 0;
	scanf_s("%d",&number);
	while (counter <= number) {
		result += 1.0 / pow(counter,5);
		counter++;
	}
	printf_s("Результат розрахунків %lf\n", result);
	
}
void Task_2F() {
	printf_s("Введіть максимальне число\n");
	int number, counter = 1;
	double result = 0;
	scanf_s("%d", &number);
	for (int counter = 1; counter <= number; counter++) {
		result += 1.0 / pow(counter, 5);
	}
	printf_s("Результат розрахунків %lf\n", result);
}
#pragma endregion
#pragma region Завдання 3
void Task_3W() {
	int formulaNumber;
	printf_s("Оберіть формулу:\n 1 - pow(x,1.0/3.0)\n 2 - 1 + ln(x)^2\n 0 - вихід\n");
	scanf_s("%d", &formulaNumber);
	double number;
	double step;
	switch (formulaNumber)
	{
	case 0:
		return;
	case 1:
		number = 3;
		step = 1;
		while (number <= 4) {
			printf_s("Результат: x = %lf, y = %lf\n", number, formula1(number));
			number += step;
		}
		break;
	case 2:
		number = 0.4;
		step = 0.1;
		while (number <= 1) {
			printf_s("Результат: x = %lf, y = %lf\n", number, formula2(number));
			number += step;
		}
		break;
	default:
		break;
	}
}
void Task_3F() {
	int formulaNumber;
	printf_s("Оберіть формулу:\n 1 - pow(x,1.0/3.0)\n 2 - 1 + ln(x)^2\n 0 - вихід\n");
	scanf_s("%d", &formulaNumber);
	switch (formulaNumber)
	{
	case 0:
		return;
	case 1:
		for (int i = 3; i <= 4; i++) {
			printf_s("Результат: x = %d, y = %lf\n",i,formula1(i));
		}
		break;
	case 2:
		for (double i = 0.4; i <= 1; i += 0.1) {
			printf_s("Результат: x = %lf, y = %lf\n", i, formula2(i));
		}
		break;
	default:
		break;
	}
}
double formula1(double x) {
	return pow(x,1.0/3.0);
}
double formula2(double x) {
	return 1 + pow(log(x),2);
}
#pragma endregion
#pragma region Самостійна
void Task_self_F() {
	printf_s("Числа:\n");
	for (int i = 1; i < 10; i++) {
		for (int n = 0; n < 10; n++) {
			for (int p = 0; p < 10; p++) {
				if (i != n && i != p && n != p) {
					printf_s("%d%d%d\n", i, n, p);
				}
			}
		}
	}
}
void Task_self_W() {
	int i = 1, n = 0, p = 0;
	printf_s("Числа:\n");
	while (i < 10) {
		while (n < 10) {
			while (p < 10) {
				if (i != n && i != p && n != p) {
					printf_s("%d%d%d\n", i, n, p);
				}
				p++;
			}
			p = 0;
			n++;
		}
		n = 0;
		i++;
	}
}
#pragma endregion