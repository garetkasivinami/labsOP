#include <stdio.h>
#include <Windows.h>
#pragma region ідентифікатори
void Task1();
void Task2();
void Self1();
void Self2();
void Self3();
void Self4();
void Self5();
#pragma endregion
#pragma region програма
int main() {
	int number;
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	while (1)
	{
		printf_s("Оберіть завдання:\n 1 - завдання 1\n 2 - завдання 2\n 3 - самостійна 1\n 4 - самостійна 2\n 5 - самостійна 3\n 6 - самостіна 4\n 7 - самостійна 5\n 0 - вихід\n");
		scanf_s("%d",&number);
		switch (number)
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
		case 5:
			Self3();
			break;
		case 6:
			Self4();
			break;
		case 7:
			Self5();
			break;
		default:
			break;
		}
	}
	return 0;
}
#pragma endregion
#pragma region завдання 1
void Task1() {
	int result = 0;
	for (int i = 0; result < 50; i++) {
		result += i;
	}
	printf_s("Результат: %d\n", result);
}
#pragma endregion
#pragma region завдання 2
void Task2() {
	int targetNumber;
	printf_s("Напишіть кількість 'ярусів' фігури\n");
	scanf_s("%d", &targetNumber);
	for (int h = 0; h < targetNumber - 1; h++) {
		for (int i = targetNumber - h; i > 1; i--) {
			printf_s("%d", i % 10);
		}
		printf_s("\n");
	}
}
#pragma endregion
#pragma region самостійна 1
void Self1() {
	int targetNumber, count, countNumbers = 0, number;
	printf_s("Напишіть задане число\n");
	scanf_s("%d", &targetNumber);
	printf_s("Напишіть кількість чисел\n");
	scanf_s("%d", &count);
	printf_s("Напишіть %d чисел через ентер\n", count);
	for (int i = 0; i < count; i++) {
		scanf_s("%d", &number);
		if (number == targetNumber) {
			countNumbers++;
		}
	}
	printf_s("Число зустрічається %d разів\n", countNumbers);
}
#pragma endregion
#pragma region самостійна 2
void Self2() {
	printf_s("Без вас гіпотеза Сіракуз не буде доведена! Введіть натуральне число для перевірки гіпотези!\n");
	int number;
	scanf_s("%d", &number);
	while (number != 1)
	{
		if (number % 2 == 0) {
			number /= 2;
		}
		else {
			number *= 3;
			number++;
			number /= 2;
		}
		printf_s("%d\n", number);
	}
	printf_s("Гіпотеза працює!!!!\n");
}
#pragma endregion
#pragma region самостійна 3
void Self3() {
	// не помітив, що потрібно натуральне число
	int number = -350000000, sum = number, currentSum, cacheNumber, currentNumber;
	do {
		printf_s("Напишіть число для перевірки суми чисел(+-). 0 - вихід з циклу\n");
		scanf_s("%d", &currentNumber);
		currentNumber = abs(currentNumber);
		currentSum = 0;
		cacheNumber = currentNumber;
		while (cacheNumber > 0) {
			currentSum += cacheNumber % 10;
			cacheNumber /= 10;
		}
		if (currentSum > sum) {
			sum = currentSum;
			number = currentNumber;
		}
	} while (currentNumber);
	printf_s("Число %d та його сума %d\n",number, sum);
}
#pragma endregion
#pragma region самостійна 4
void Self4() {
	printf_s("Напишіть символ для виведення 'уявної' діагоналі\n");
	char sumvol;
	scanf_s(" %c", &sumvol);
	for (int i = 0; i < 30; i++) {
		for (int h = 0; h < i * 2; h++) {
			printf_s(" ");
		}
		printf_s("%c\n", sumvol);
	}
}
#pragma endregion
#pragma region самостійна 5
void Self5() {
	int number;
	printf_s("Напишіть натуральне число\n");
	scanf_s("%d", &number);
	printf_s("Його множники:\n");
	while (number > 1)
	{
		int index = 2;
		while (number % index != 0)
		{
			index++;
		}
		number /= index;
		printf_s("%d\n", index);
	}
}
#pragma endregion