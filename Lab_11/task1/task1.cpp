#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>

#pragma region ідентифікатори
void Task1();
void Task2();
void Task3();
void Task4();
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
		scanf_s("%d", &number);
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
		scanf_s("%d", &selectGenerator);
		switch (selectGenerator)
		{
		case 0:
			return;
		case 1:
			printf_s("%d\n",(rand() % 4) - 4);
			break;
		case 2:
			printf_s("%d\n", (rand() % 200) + 100);
			break;
		case 3:
			printf_s("%d\n", (rand() % 200) + 100);
			break;
		case 4:
			printf_s("%d\n", (rand() % 256) - 128);
			break;
		case 5:
			printf_s("%d\n", (rand() % 256) - 128);
			break;
		case 6:
			printf_s("%d\n", (rand() % 256) - 128);
			break;
		case 7:
			printf_s("%d\n", (rand() % 2));
			break;
		case 8:
			printf_s("%d\n", (23 + rand() % 71 - 23));
			break;
		case 9:
			printf_s("%d\n", rand() % 2);
			break;
		case 10:
			printf_s("%d\n", (rand() % 256) - 128);
			break;
		default:
			break;
		}
	}
}
#pragma endregion
#pragma region завдання 2
void Task2() {
	int k;
	scanf_s("%d",&k);
	for (int i = 0; i < 30; i++) {
		printf_s("%4d", 13 + (rand() % (400 - 13)));
		if ((i + 1) % k == 0 || i == 29) {
			printf_s("\n");
		}
	}
	printf_s("Наступний рандом\n");
	for (int i = 0; i < 30; i++) {
		printf_s("%f ", (-20 + (rand() % 41)) * 0.1);
		if ((i + 1) % k == 0 || i == 29) {
			printf_s("\n");
		}
	}
}
#pragma endregion
#pragma region завдання 3
void Task3() {
	int Lenght = 10;
	int dobSumm = 0;
	int result = 0;
	int* mass = (int*)malloc(Lenght * sizeof(int));
	for (int i = 0; i < Lenght; i++) {
		mass[i] = rand() % 20 - 10;
		if (mass[i] > 0) {
			dobSumm += mass[i];
		}
		printf_s("--- %d\n", mass[i]);
	}
	int indexMin = 0;
	int indexMax = 0;
	for (int i = 1; i < Lenght; i++) {
		if (mass[indexMin] > mass[i]) {
			indexMin = i;
		}
		if (mass[indexMax] < mass[i]) {
			indexMax = i;
		}
	}
	if (indexMax == indexMin) {
		printf_s("Чики брики!");
		return;
	}
	if (indexMax < indexMin) {
		int temp = indexMax;
		indexMax = indexMin;
		indexMin = temp;
	}
	for (int i = indexMin; i < indexMax + 1; i++) {
		result += mass[i];
	}
	printf_s("Сума додатніх елементів %d, сума між мінімумом та максимумом %d\n", dobSumm, result);
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