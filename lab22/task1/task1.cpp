#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
void Task1();
void Task2();
template <typename T>
void PrintMatrix(T**, int, int, const char st[4]);
void SwapColToEnd(int**, int, int, int);
void SwapLineToEnd(int**, int, int, int);
void HorResize(int**, int, int);
void VerResize(int**, int);
template <typename T>
void Swap(T&, T&);
int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(0));
	int task;
	while (1) {
		printf_s("Оберіть завдання:\n 1 - завдання 1\n 2 - завдання 2\n 0 - вихід\n");
		scanf_s("%d", &task);
		switch (task)
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
	int sizeX = 4, sizeY = 4, **matrix = NULL;
	int minV, maxV;
	do {
		printf_s("Min = ");scanf_s("%d", &minV);
		printf_s("Max = ");scanf_s("%d", &maxV);
	} while (minV > maxV);
	matrix = (int**)malloc(sizeof(int) * sizeX);
	for (int i = 0; i < sizeX; i++) {
		matrix[i] = (int*)malloc(sizeof(int*) * sizeY);
		for (int y = 0; y < sizeY; y++) {
			matrix[i][y] = minV + rand() % (maxV - minV + 1);
		}
	}
	PrintMatrix(matrix, sizeX, sizeY, "%3d");
	int* arr = (int*)malloc(sizeof(int*) * sizeY);
	for (int i = 0; i < sizeY; i++) {
		int* min = &matrix[0][i];
		for (int x = 1; x < sizeX; x++) {
			if (matrix[x][i] < *min) {
				min = &matrix[x][i];
			}
		}
		arr[i] = *min;
		printf_s("Adress of %d min element: %p and value %d\n", i, min, *min);
	}
}
void Task2() {
	int sizeX = 5, sizeY = 5, **matrix = NULL;
	matrix = (int**)malloc(sizeof(int*) * sizeX);
	for (int i = 0; i < sizeX; i++) {
		matrix[i] = (int*)malloc(sizeof(int*) * sizeY);
		for (int y = 0; y < sizeY; y++) {
			matrix[i][y] = rand() % 51 - 25;
		}
	}
	PrintMatrix(matrix, sizeX, sizeY, "%3d");
	int target;
	printf_s("Write target number:");
	scanf_s("%d", &target);
	target--;
	SwapColToEnd(matrix, sizeX, sizeY, target);
	HorResize(matrix, sizeX, --sizeY);
	PrintMatrix(matrix, sizeX, sizeY, "%3d");
	target = 0;
	int minElement = matrix[0][0];
	for (int i = 0; i < sizeX; i++) {
		for (int x = 0; x < sizeY; x++) {
			if (minElement > matrix[i][x]) {
				minElement = matrix[i][x];
				target = i;
			}
		}
	}
	SwapLineToEnd(matrix, sizeX, sizeY,target);
	VerResize(matrix, --sizeX);
	PrintMatrix(matrix, sizeX, sizeY, "%3d");
	printf_s("End!");
}
template <typename T>
void PrintMatrix(T** arr, int sizeX, int sizeY, const char st[4]) {
	printf_s("Matrix\n");
	for (int x = 0; x < sizeX; x++) {
		for (int y = 0; y < sizeY; y++) {
			printf_s(st, arr[x][y]);
			if (y < sizeY - 1) {
				printf_s(" ");
			}
		}
		printf_s("\n");
	}
	printf_s("/Matrix\n");
}
void SwapColToEnd(int** arr, int sizeX, int sizeY, int target) {
	if (target == sizeY - 1) {
		return;
	}
	for (int i = target; i < sizeY - 1; i++) {
		for (int n = 0; n < sizeX; n++) {
			Swap(arr[n][i], arr[n][i+1]);
		}
	}
}
void SwapLineToEnd(int** arr, int sizeX, int sizeY, int target) {
	if (target == sizeX - 1) {
		return;
	}
	for (int i = target; i < sizeX - 1; i++) {
		for (int n = 0; n < sizeY; n++) {
			Swap(arr[i][n], arr[i + 1][n]);
		}
	}
}
template <typename T>
void Swap(T &a, T &b) {
	T temp = a;
	a = b;
	b = temp;
}
void HorResize(int** arr, int sizeX, int newLength) {
	for (int i = 0; i < sizeX; i++) {
		arr[i] = (int*)realloc(arr[i], newLength * sizeof(int*));
	}
}
void VerResize(int** arr, int newLength) {
	arr = (int**)realloc(arr, newLength * sizeof(int*));
	int m = 29;
	int* p = &m;
}
/*
char c; int* pi; float** ppf;
char* cp = &c;
char cpp = *(&c);
int* ip = &pi[0];
int* ip1 = &(pi + 10); // не работае
float* ip1 = & &ppf; // не работае
float* ip2 = ppf[10];
float ip3 = (*ppf)[3];
*/