#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include <math.h>
#pragma region ідентифікатори
void Task1();
void Task2();
void Task3();
void Task4();
int random(int min, int max);
void PrintMassive(int* massive, int lenght) {
	printf_s("{");
	for (int i = 0; i < lenght; i++) {
		printf_s("%d", massive[i]);
		if (i != lenght - 1) {
			printf_s(" ");
		}
	}
	printf_s("}\n");
}
#pragma endregion
#pragma region програма
int  main(){
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(0));
	int number;
	while (1) {
		printf_s("Оберіть завдання:\n 1 - завдання 1\n 2 - завдання 2\n 3 - завдання 3\n 4 - завдання 4\n");
		scanf_s("%d", &number);
		switch (number)
		{
		case 0:
			return 0;
		case 1:
			//printf_s("*РЕЖИМ ТЕСТУВАННЯ*\n кожний елемент буде написано 3 рази!\n");
			Task1();
			break;
		case 2:
			Task2();
			break;
		case 3:
			Task3();
			break;
		case 4:
			Task4();
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
	int selectGenerator;
	while(1) {
		printf_s("Оберіть генератор псевдовипадкових чисел(1-10)!\n 0 - вихід\n");
		scanf_s("%d", &selectGenerator);
		switch (selectGenerator)
		{
		case 0:
			return;
		case 1:
			printf_s("%d\n",random(-4,-2));
			break;
		case 2:
			printf_s("%d\n", random(100,299));
			break;
		case 3:
			printf_s("%d\n", random(-17,0) * 2);
			break;
		case 4:
			printf_s("%d\n", random(-128,127));
			break;
		case 5:
			printf_s("%d\n", random(-4,6) * 2 + 1);
			break;
		case 6:
			printf_s("%f\n", -7.85 + (rand() % (2830 + 785)) / 100.0);
			break;
		case 7:
			printf_s("%d\n", random(-100, 100));
			break;
		case 8:
			printf_s("%d\n", random(23, 70));
			break;
		case 9:
			printf_s("%d\n", random(0, 1));
			break;
		case 10:
			printf_s("%f\n", sqrt(17) + (rand() % (int)((sqrt(82) - sqrt(17)) * 1000) / 1000.0));
			break;
		default:
			break;
		}
	}
}
#pragma endregion
#pragma region завдання 2
void Task2() {
	int k, n, m;
	printf_s("Напишить кількість випадкових чисел для 'а' та 'б' через пробіл\n");
	scanf_s("%d %d", &n, &m);
	printf_s("Напишіть кількість чисел, яка буде виводитися в одній стрічці.\n");
	scanf_s("%d",&k);
	for (int i = 1; i <= n; i++) {
		printf_s("%4d", random(13,399));
		if (i % k == 0 || i == n) {
			printf_s("\n");
		}
	}
	printf_s("Наступний рандом\n");
	for (int i = 1; i <= m; i++) {
		printf_s("%.1f ", random(-20,20) * 0.1);
		if (i % k == 0 || i == m) {
			printf_s("\n");
		}
	}
}
#pragma endregion
#pragma region завдання 3
void Task3() {
	int Lenght = 10;
	int dobSumm = 0;
	int result = 1;
	int* mass = (int*)malloc(Lenght * sizeof(int));
	for (int i = 0; i < Lenght; i++) {
		mass[i] = rand() % 20 - 10;
		if (mass[i] > 0) {
			dobSumm += mass[i];
		}
	}
	PrintMassive(mass,Lenght);
	int indexMin = 0;
	int indexMax = 0;
	for (int i = 1; i < Lenght; i++) {
		if (abs(mass[indexMin]) > abs(mass[i])) {
			indexMin = i;
		}
		if (abs(mass[indexMax]) < abs(mass[i])) {
			indexMax = i;
		}
	}
	if (indexMax == indexMin) {
		printf_s("Сума додатніх елементів %d!", dobSumm);
		return;
	}
	if (indexMax < indexMin) {
		int temp = indexMax;
		indexMax = indexMin;
		indexMin = temp;
	}
	for (int i = indexMin + 1; i < indexMax; i++) {
		result *= mass[i];
	}
	printf_s("Сума додатніх елементів %d, добуток між мінімумом та максимумом за модулем %d\n", dobSumm, result);
	free(mass);
}
#pragma endregion
#pragma region завдання 4
void Task4() {
	int maxNumber = -2000000000;
	int lenght = 10;
	int* X = new int[lenght];
	int* Y = new int[lenght];
	int* Z = new int[lenght];
	for (int i = 0; i < 10; i++) {
		X[i] = rand()%200 - 100;
		Y[i] = rand() % 200 - 100;
	}
	printf_s("X = "); PrintMassive(X, lenght);
	printf_s("Y = "); PrintMassive(Y, lenght);
	for (int i = 0; i < 10; i++) {
		Z[i] = X[i] + Y[10 - i - 1];
		if (Z[i] > maxNumber) {
			maxNumber = Z[i];
		}
	}
	printf_s("Z = "); PrintMassive(Z, lenght);
	printf_s("Максимальний елемент: %d\n", maxNumber);
}
#pragma endregion
#pragma region інше
int random(int min, int max) { // включно максимум
	return (min + rand() % (max - min + 1));
}
#pragma endregion
