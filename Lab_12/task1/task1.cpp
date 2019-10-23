#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#pragma region ідентифікатори
const int sizeInt = sizeof(int);
void swap(int& a, int& b);
void Task1();
void Task2();
void Task3();
void Task3_1_3(int* mass, int lenght, int koef);
void Task3_1_4(int* mass, int lenght, int koef);
void Task3_2_1(int* mass, int lenght);
int Task3_3_1(int* mass, int lenght, int target);
void Self1();
void Self2();
void check();
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
int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(NULL));
	check();
	int number;
	while (1) {
		printf_s("Оберіть номер завдання:\n 1 - завдання 1\n 2 - завдання 2\n 3 - завдання 3\n 4 - самостійна 1\n 5 - самостійна 2\n 0 - вихід\n");
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
			Self1();
			break;
		case 5:
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
	int lenght = 20;
	int index = -1;
	int* massive = (int*)malloc(lenght * sizeof(int));
	for (int i = 0; i < lenght; i++) {
		massive[i] = -10 + rand() % 21;
	}
	for (int i = 1; i < lenght - 1; i++) {
		if (massive[i - 1] < massive[i] && massive[i + 1] < massive[i]) {
			index = i;
		}
	}
	if (index == -1) {
		printf_s("Index = -1\n");
	}
	else {
		printf_s("Індекс останнього локального максимуму %d\n",index);
	}
	free(massive);
}
#pragma endregion
#pragma region завдання 2
void Task2() {
	int lenght = 7;
	int maxA = 0, maxB = 0;
	int* a = (int*)malloc(lenght * sizeInt);
	int* b = (int*)malloc(lenght * sizeInt);
	int* c = (int*)malloc(lenght * sizeInt);
	for (int i = 0; i < lenght; i++) {
		a[i] = rand() % 1000 - 500;
		b[i] = rand() % 1000 - 500;
		c[i] = 0;
		if (a[i] > a[maxA]) {
			maxA = i;
		}
		if (b[i] >	b[maxB]) {
			maxB = i;
		}
	}
	if (maxA == maxB) {
		c[maxA] = (a[maxA] > b[maxB]) ? a[maxA] : b[maxB];
	}
	else {
		c[maxA] = a[maxA];
		c[maxB] = b[maxB];
	}
	printf_s("a = "); PrintMassive(a, lenght);
	printf_s("b = "); PrintMassive(b, lenght);
	printf_s("c = "); PrintMassive(c, lenght);
	
}
#pragma endregion
#pragma region завдання 3
void swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}
void Task3() {
	int size = 20;
	int* massive = (int*)malloc(sizeInt * size);
	for (int i = 0; i < 20; i++) {
		massive[i] = -500 + rand() % 1000;
	}
	printf_s("mass = "); PrintMassive(massive, size);
	Task3_1_3(massive, size, 1);
	Task3_1_4(massive, size, 1);
	Task3_2_1(massive, size);
	size = Task3_3_1(massive,size, 5);
	printf_s("mass = "); PrintMassive(massive, size);
	printf_s("%d\n", size);
	free(massive);
}
// перший та другий пункт 1.3-1.4
void Task3_1_3(int* mass, int lenght, int koef) {
	printf_s("Пункт 1.3\n");
	int temp;
	for (int d = 0; d < koef; d++) {
		temp = mass[lenght - 1];
		for (int i = lenght - 1; i > 0; i--) {
			mass[i] = mass[i - 1];
		}
		mass[0] = temp;
	}
	printf_s("mass = ");PrintMassive(mass, lenght);
}
void Task3_1_4(int* mass, int lenght, int koef) {
	printf_s("Пункт 1.4\n");
	int temp;
	for (int d = 0; d < koef; d++) {
		temp = mass[0];
		for (int i = 0; i < lenght - 1; i++) {
			mass[i] = mass[i + 1];
		}
		mass[lenght - 1] = temp;
	}
	printf_s("mass = ");PrintMassive(mass, lenght);
}
void Task3_2_1(int* mass, int lenght) {
	printf_s("Пункт 2.1\n");
	mass[0] = 10 + rand() % 20;
	for (int i = 1; i < lenght; i++) {
		mass[i] = i * 2;
	}
	printf_s("mass = ");PrintMassive(mass, lenght);
	for (int i = 1; i < lenght; i++) {
		if (mass[i - 1] > mass[i]) {
			swap(mass[i-1],mass[i]);
		}
		else {
			break;
		}
	}
	printf_s("mass = ");PrintMassive(mass, lenght);
}
int Task3_3_1(int* mass, int lenght, int target) {
	printf_s("Пункт 3.1\n видалення елементу номер %d\n", target);
	for (int i = target; i < lenght - 1; i++) {
		mass[i] = mass[i + 1];
	}
	int newSize = lenght - 1;
	mass = (int*)realloc(mass, newSize * sizeInt);
	return newSize;
}
#pragma endregion
#pragma region самостійні
void Self1() {
	int* massive = new int[11];
	for (int i = 0; i < 11; i ++) {
		massive[i] = -100 + rand() % 200;
	}
	PrintMassive(massive, 11);
	printf_s("Сортування....\n");
	int indexLastPlus = 0;
	int minusCount = 0;
	for (int i = 0; i < 11; i++) {
		if (massive[i] > 0) {
			swap(massive[i], massive[indexLastPlus]);
			indexLastPlus++;
		}
		else {
			minusCount++;
		}
	}
	PrintMassive(massive, 11);
}
void Self2() {
	int* massive = new int[14];
	for (int i = 0; i < 14; i++) {
		massive[i] = -100 + rand() % 200;
	}
	PrintMassive(massive, 11);
	printf_s("Сортування....\n");
	int targetIndex = 0;
	for (int i = 1; i < 14; i++) {
		if (massive[i] > massive[targetIndex]) {
			for (int z = i; z > targetIndex; z--) {
				swap(massive[z], massive[z - 1]);
			}
			targetIndex++;
		}
	}
	PrintMassive(massive, 14);
}
#pragma endregion
#pragma region перев
void check() {
	int lenght = 10;
	int* a = (int*)malloc(sizeInt * lenght);
	int* b = (int*)malloc(sizeInt * lenght);
	int* c = (int*)malloc(sizeInt * lenght * 2);
	for (int i = 0; i < lenght; i++) {
		a[i] = -10 + rand() % 10;
		b[i] = rand() % 10;
		if (a[i] > b[i]) {
			c[i * 2] = b[i];
			c[i * 2 + 1] = a[i];
		}
		else {
			c[i * 2 + 1] = b[i];
			c[i * 2] = a[i];
		}
	}
	printf_s("a = ");PrintMassive(a, lenght);
	printf_s("b = ");PrintMassive(b, lenght);
	printf_s("c = ");PrintMassive(c, lenght * 2);
}
#pragma endregion
