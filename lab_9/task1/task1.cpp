#include <stdio.h>
#include <math.h>
#include <Windows.h>
#pragma region Ідентифікатори
void Task1();
void Task2();
void Self1();
void Self2();
#pragma endregion
#pragma region Програма
int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int selectTask;
	while (1) {
		printf_s("Оберіть завдання:\n 1 - завдання 1\n 2 - завдання 2\n 3 - самостійна 1\n 4 - самостійна 2\n 0 - вихід\n");
		scanf_s("%d", &selectTask);
		switch (selectTask)
		{
		case 0:
			return 0;
		case 1:
			Task1();
			break;
		case 2:
			Task2();
			break;
		case 3:
			Self1();
			break;
		case 4:
			Self2();
			break;
		default:
			break;
		}
	}
}
#pragma endregion
#pragma region завдання 1
void Task1() {
	while (1)
	{
		int modeWork, countNumbers = -1;
		int scanNumber = 1;
		int sum = -1, dobytok = 1;
		printf_s("Обчислення добутку та суми введених чисел, для закінчення вводу цифр введіть 0\n Оберіть режим роботи:\n 1 - while\n 2 - do-while\n 0 - вихід\n");
		scanf_s("%d", &modeWork);
		switch (modeWork)
		{
		case 0:
			return;
		case 1:
			while (scanNumber)
			{
				countNumbers++;
				sum += scanNumber;
				dobytok *= scanNumber;
				scanf_s("%d", &scanNumber);
			}
			break;
		case 2:
			do
			{
				countNumbers++;
				sum += scanNumber;
				dobytok *= scanNumber;
				scanf_s("%d", &scanNumber);
			} while (scanNumber);
			break;
		default:
			break;
		}
		printf_s("Сума чисел %d, добуток чисел %d, кількість чисел %d\n", sum, dobytok, countNumbers);
	}
}
#pragma endregion
#pragma region завдання 2
void Task2() {
	int targetNumber;
	while(1){
		printf_s("Введіть чотирьох значне число, якщо число менше 1000 - вихід\n");
		scanf_s("%d", &targetNumber);
		if (targetNumber < 1000) {
			return;
		}
		printf_s("Сума чисел %d, добуток чисел %d\n", (targetNumber / 10) % 10 + (targetNumber / 100) % 10, ((targetNumber / 10) % 10) * ((targetNumber / 100) % 10));
	}
}
#pragma endregion
#pragma region Самостійна 1
void Self1() {
	int count10 = 0, count5 = 0, number;
	printf_s("Напишіть 10 чисел\n");
	for (int i = 0; i < 10; i++) {
		scanf_s("%d",&number);
		if (number > 10) {
			count10++;
			count5++;
		}
		else if (number > 5) {
			count5++;
		}
	}
	if (count10 > 4) {
		printf_s("Караул!!!\n");
	}
	else {
		printf_s("Кількість чисел більше 10 - %d, кількість чисел більше 5 - %d\n", count10, count5);
	}
}
#pragma endregion
#pragma region Самостійна 2
void Self2() {
	printf_s("напишіть число таймера(в мілісекундах)\n");
	int sleeptime;
	scanf_s("%d",&sleeptime);
	Sleep(sleeptime);
	printf_s("\a");
}
#pragma endregion