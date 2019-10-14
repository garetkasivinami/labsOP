#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#pragma region ідентифікатори
const int sizeInt = sizeof(int);
void Task1();
void Task2();
void Task3();
void Task3_1and2();
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
	int number;
	Task3_1and2();
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
		default:
			break;
		}
	}
}
#pragma endregion
#pragma region завдання 1
void Task1() {
	int lenght = 10;
	int index = -1;
	int* massive = (int*)malloc(lenght * sizeof(int));
	for (int i = 1; i < lenght - 1; i++) {
		if (massive[i - 1] < massive[i] && massive[i + 1] < massive[i]) {
			index = i;
		}
	}
	if (index == -1) {
		printf_s("NOOOOO");
	}
	else {
		printf_s("%d",index);
	}
	free(massive);
}
#pragma endregion
#pragma region завдання 2
void Task2() {
	int lenght = 15;
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
void Task3() {

}
// перший та други пункт 1.1-1.2
void Task3_1and2() {
	int lenght = 5;
	int kDelta = 1;
	int* massive = new int[lenght];
	int** temp = new int*[lenght];
	for (int i = 0; i < lenght; i++) {
		massive[i] = int(rand() % 100);
	}
	printf_s("mass = ");PrintMassive(massive, lenght);
	if (kDelta < 0) {
		kDelta = -(abs(lenght + kDelta) % lenght);
	}
	for (int i = 0; i < lenght; i++) {
		int index = (i - kDelta) % lenght;
		printf_s("%d\n", index);
		temp[i] = &massive[(index < 0) ? (lenght + index) % lenght : index];
		printf_s("++%d %d\n", i, (index < 0) ? (lenght + index) % lenght : index);
	}
	for (int i = 0; i < lenght; i++) {
		massive[i] = *temp[i];
		printf_s("--%d\n",*temp[i]);
	}
	printf_s("mass = ");PrintMassive(massive, lenght);
}
#pragma endregion