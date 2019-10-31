#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#pragma region Ідентифікатори
void grebinetsMethod(int* mass, int lenght);
void Task1();
void Task2();
void Task3();
void uchooseMethotMatrix(unsigned int** mass, int sizeX, int sizeY);
void upasteMethotMatrix(unsigned int** mass, int sizeX, int sizeY);
void swap(int& a, int& b);
void uswap(unsigned int& a, unsigned int& b);
void PrintMatrix(int** massive, int lenghtX, int lenghtY) {
	for (int i = 0; i < lenghtX; i++) {
		for (int j = 0; j < lenghtY; j++) {
			printf_s("%4d", massive[i][j]);
		}
		printf_s("\n");
	}
}
void uPrintMatrix(unsigned int** massive, int lenghtX, int lenghtY) {
	for (int i = 0; i < lenghtX; i++) {
		for (int j = 0; j < lenghtY; j++) {
			printf_s("%4d", massive[i][j]);
		}
		printf_s("\n");
	}
}
#pragma endregion
#pragma region програма
int main() {
	srand(time(NULL));
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int number;
	while (1) {
		printf_s("Оберіть режим роботи програми:\n 1 - завдання 1\n 2 - завдання 2\n 3 - завдання 3\n 0 - вихід\n");
		scanf_s("%d", &number);
		switch (number)
		{
		case 0:
			return 0;
			break;
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
#pragma region сортувальники
void uchooseMethotMatrix(unsigned int** mass, int sizeX, int sizeY) {
	for (int x = 0; x < sizeX; x++) {
		for (int y = 0; y < sizeY; y++) {
			int minX = x, minY = y;
			int ty = y;
			for (int tx = x; tx < sizeX; tx++) {
				for (; ty < sizeY; ty++) {
					if (mass[tx][ty] < mass[minX][minY]) {
						minX = tx;
						minY = ty;
					}
				}
				ty = 0;
			}
			uswap(mass[x][y],mass[minX][minY]);
		}
	}
}

void upasteMethotMatrix(unsigned int** mass, int sizeX, int sizeY) {
	int y = 1;
	for (int x = 0; x < sizeX; x++) {
		for (; y < sizeY; y++) {
			int ty = y - 1;
			int tx = (ty == -1)? (ty = sizeY - 1,x - 1): x;
			for (; tx >= 0; tx--) {
				unsigned int* element;
				for (; ty >= 0 && (element = &((ty + 1 == sizeY) ? mass[tx + 1][0] : mass[tx][ty + 1]) , mass[tx][ty] > *element); ty--) {
					uswap(mass[tx][ty], *element);
				}
				ty = sizeY - 1;
			}
		}
		y = 0;
	}
}

void uswap(unsigned int& a, unsigned int& b) {
	unsigned int temp = a;
	a = b;
	b = temp;
}
void swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}
int newGap(int gap)
{
	gap /= 1.3;

	if (gap == 9 || gap == 10)
		gap = 11;
	if (gap < 1)
		return 1;

	return gap;
}
void grebinetsMethod(int* mass, int lenght) {
	int flag = 1;
	int gap = lenght;
	while (flag || gap > 1) {
		flag = 0;
		gap = newGap(gap);
		for (int i = 0; i < lenght - gap; i++) {
			if (mass[i + gap] < mass[i]) {
				swap(mass[i + gap], mass[i]);
				flag = 1;
			}
		}
	}
}
#pragma endregion
#pragma region завдання 1
void Task1() {
	int** matrix = new int* [5];
	for (int i = 0; i < 5; i++) {
		matrix[i] = new int[5];
		for (int y = 0; y < 5; y++) {
			matrix[i][y] = -10 + rand() % 20;
		}
	}
	PrintMatrix(matrix, 5, 5);
	for (int i = 1; i <= 5; i++) {
		if (i % 2 == 1) {
			grebinetsMethod(matrix[i - 1], 5);
		}
	}
	printf_s("Відсортована матриця:\n");
	PrintMatrix(matrix, 5, 5);
}
#pragma endregion
#pragma region завдання 2
void MethodOne(int* massive, int size, int k) {
	k = k % size;
	for (int i = 0; i < k; i++) {
		int temp = massive[size - 1];
		for (int j = size - 1; j > 0; j--) {
			massive[j] = massive[j - 1];
		}
		massive[0] = temp;
	}
}
int* MethodTwo(int* massive, int size, int k) {
	k = (k >= 0)? k % size: size - (-k % size);
	int* temp = new int[size];
	for (int i = 0; i < size; i++) {
		temp[(i + k) % size] = massive[i];
	}
	free(massive);
	return temp;
}
void Task2() {
	int sizeX = rand() % 4 + 3, sizeY = rand() % 4 + 3;
	int k;
	printf_s("Напишіть коефіцієнт зміщення\n");
	scanf_s("%d", &k);
	int** matrix = new int* [sizeX];
	for (int i = 0; i < sizeX; i++) {
		matrix[i] = new int[sizeY];
		for (int y = 0; y < sizeY; y++) {
			matrix[i][y] = rand() % 20 - 10;
		}
	}
	PrintMatrix(matrix, sizeX, sizeY);
	for (int i = 0; i < sizeX; i++) {
		if (i % 2 == 1) {
			matrix[i] = MethodTwo(matrix[i],sizeY, k);
		}
	}
	printf_s("Зміщення матриця\n");
	PrintMatrix(matrix, sizeX, sizeY);
}
#pragma endregion
#pragma region завдання 3
void Task3() {
	unsigned int** matrix = new unsigned int* [7];
	for (int i = 0; i < 7; i++) {
		matrix[i] = new unsigned int[9];
		for (int y = 0; y < 9; y++) {
			matrix[i][y] = rand() % 200;
		}
	}
	uPrintMatrix(matrix, 7, 9);
	printf_s("Метод вибору\n");
	uchooseMethotMatrix(matrix,7,9);
	uPrintMatrix(matrix, 7, 9);
	for (int i = 0; i < 7; i++) {
		matrix[i] = new unsigned int[9];
		for (int y = 0; y < 9; y++) {
			matrix[i][y] = rand() % 200;
		}
	}
	printf_s("Метод вставок (згенеровано нову матрицю)\n");
	upasteMethotMatrix(matrix,7,9);
	printf_s("----------------------------------\n");
	uPrintMatrix(matrix, 7, 9);
}
#pragma endregion