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
void ChooseMethotMatrix(int** mass, int sizeX, int sizeY);
void pasteMethotMatrix(int** mass, int sizeX, int sizeY);
void check();
void Trololo();
void Chtoto();
#pragma endregion
#pragma region програма
void MPasteMethotMatrix();
void MChooseMethotMatrix();
int main() {
	srand(time(NULL));
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Chtoto();
	return 0;
	unsigned int** matrix = new unsigned int* [10];
	for (int i = 0; i < 10; i++) {
		matrix[i] = new unsigned int[10];
		for (int g = 0; g < 10; g++) {
			matrix[i][g] = rand() % 201;
		}
	}
	MChooseMethotMatrix();
	printf_s("\n");
	return 0;
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

void uBoobleMethotMatrix(int** mass, int sizeX, int sizeY) {
	int flag = 1, ti, tj;
	while (flag)
	{
		int j = 1;
		flag = 0;
		for (int i = 0; i < sizeX; i++) {
			for (i; j < sizeY; j++) {
				tj = (j == 0) ? (ti = i - 1, sizeY - 1) : (ti = i, j - 1);
				if (mass[i][j] > mass[ti][tj]) {
					swap(mass[i][j], mass[ti][tj]);
					flag = 1;
				}
			}
			j = 0;
		}
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
#pragma region перевірка
void check() {
	int sizef = 8, hsizef = sizef / 2;
	int sizes = 8, hsizes = sizef / 2;
	int summ = 0;
	int** mass = new int*[sizef];
	for (int i = 0; i < sizef; i++) {
		mass[i] = new int[sizes];
		for (int j = 0; j < sizes; j++) {
			mass[i][j] = -10 + rand() % 21;
		}
	}
	PrintMatrix(mass,sizef,sizes);
	for (int i = 0; i < hsizef; i++) {
		for (int j = 0; j < i + 1; j++) {
			summ += mass[i][j];
			summ += mass[sizef - i - 1][j];
			summ += mass[i + hsizef][j + hsizes];
		}
	}
	printf_s("%d\n", summ);
	/*ПЕРЕВІРКА ПРАВИЛЬНОСТІ АЛГОРИТМУ*/
	printf_s("Перевірка правильності алгориму\n");
	for (int i = 0; i < sizef; i++) {
		for (int j = 0; j < sizes; j++) {
			mass[i][j] = 0;
		}
	}
	for (int i = 0; i < hsizef; i++) {
		for (int j = 0; j < i + 1; j++) {
			mass[i][j] = 1;
			mass[sizef - i - 1][j] = 1;
			mass[i + hsizef][j + hsizes] = 1;
		}
	}
	for (int i = 0; i < sizef; i++) {
		for (int j = 0; j < sizes; j++) {
			printf_s("%2d",mass[i][j]);
		}
		printf_s("\n");
	}
}
/*
#pragma endregion
void SanyaHelp() {
	int mass[5][5];
	int minIndex = 0, min, maxIndex = 0, max, temp = 0;
	for (int i = 0; i < 5; i++) {
		temp += mass[i][0];
	}
	min = temp;
	max = temp;
	for (int j = 1; j < 5; j++) {
		temp = 0;
		for (int i = 0; i < 5; i++) {
			temp += mass[i][j];
		}
		if (temp < min) {
			min = temp;
			minIndex = j;
		}
		if (temp > max) {
			max = temp;
			maxIndex = j;
		}
	}
	for (int j = 0; j < 5; j++) {
		temp = mass[j][minIndex];
		mass[j][minIndex] = mass[j][maxIndex];
		mass[j][maxIndex] = temp;
	}
}
*/

// сортування
void pasteMethotMatrix(int** mass, int sizeX, int sizeY) {
	int y = sizeY - 2;
	for (int x = sizeX - 1; x >= 0; x--) {
		for (; y >= 0; y--) {
			int dy = y + 1;
			int dx = (dy == sizeY) ? (dy = 0, x + 1): x;
			for (; dx < sizeX; dx++) {
				int* link;
				for (; dy < sizeY && (link = &((dy - 1 == -1)? mass[dx - 1][sizeY - 1]:mass[dx][dy - 1]), mass[dx][dy] < *link); dy++) {
					swap(mass[dx][dy], *link);
				}
				dy = 0;
			}
		}
		y = sizeY - 1;
	}
}
void ChooseMethotMatrix(int** mass, int sizeX, int sizeY) {
	int y = sizeY - 1;
	for (int x = sizeX - 1; x >= 0; x--) {
		for (; y >= 0; y--) {
			int maxX = x, maxY = y;
			int dy = y;
			for (int dx = x; dx >= 0; dx--) {
				for (; dy >= 0; dy--) {
					if (mass[dx][dy] > mass[maxX][maxY]) {
						maxX = dx;
						maxY = dy;
					}
				}
				dy = sizeY - 1;
			}
			swap(mass[maxX][maxY],mass[x][y]);
		}
		y = sizeY - 1;
	}
}

void Trololo(){
	const int sizeX = 3, sizeY = 3;
	int matrix[sizeX][sizeY];
	for (int i = 0; i < sizeX; i++) {
		for (int y = 0; y < sizeY; y++) {
			matrix[i][y] = rand() % 4;
			printf_s("%2d", matrix[i][y]);
		}
		printf_s("\n");
	}
	for (int i = 0; i < sizeX; i++) {
		for (int j = 0; j < sizeY; j++) {
			if (matrix[i][j] == matrix[j][i]) {
				if (j == sizeY - 1) {
					printf_s("k = %d\n", i);
				}
			}
			else {
				break;
			}
		}
	}
}
void MSwap(unsigned int& a, unsigned int& b) {
	unsigned int temp = a;
	a = b;
	b = temp;
}
void MPasteMethotMatrix() {
	const int sizeX = 9, sizeY = 9;
	unsigned int mass[sizeX][sizeY];
	for (int i = 0; i < sizeX; i++) {
		for (int y = 0; y < sizeY; y++) {
			mass[i][y] = rand() % 201;
			printf_s("%4d", mass[i][y]);
		}
		printf_s("\n");
	}
	int y = sizeY - 2;
	for (int x = sizeX - 1; x >= 0; x--) {
		for (; y >= 0; y--) {
			int dy = y + 1;
			int dx;
			if (dy == sizeY) {
				dy = 0;
				dx = x + 1;
			}
			else {
				dx = x;
			}
			for (; dx < sizeX; dx++) {
				int iX;
				int iY;
				for (;dy < sizeY; dy++) {
					if (dy - 1 == -1) {
						iX = dx - 1;
						iY = sizeY - 1;
					}
					else {
						iX = dx;
						iY = dy - 1;
					}
					if (mass[dx][dy] <= mass[iX][iY]) {
						break;
					}
					MSwap(mass[dx][dy], mass[iX][iY]);
				}
				dy = 0;
			}
		}
		y = sizeY - 1;
	}
	printf_s("Result:\n");
	for (int i = 0; i < sizeX; i++) {
		for (int y = 0; y < sizeY; y++) {
			printf_s("%4d", mass[i][y]);
		}
		printf_s("\n");
	}
}
void MChooseMethotMatrix() {
	const int sizeX = 9, sizeY = 9;
	unsigned int mass[sizeX][sizeY];
	for (int i = 0; i < sizeX; i++) {
		for (int y = 0; y < sizeY; y++) {
			mass[i][y] = rand() % 201;
			printf_s("%4d", mass[i][y]);
		}
		printf_s("\n");
	}
	int y = sizeY - 1;
	for (int x = sizeX - 1; x >= 0; x--) {
		for (; y >= 0; y--) {
			int maxX = x, maxY = y;
			int dy = y;
			for (int dx = x; dx >= 0; dx--) {
				for (; dy >= 0; dy--) {
					if (mass[dx][dy] < mass[maxX][maxY]) {
						maxX = dx;
						maxY = dy;
					}
				}
				dy = sizeY - 1;
			}
			MSwap(mass[maxX][maxY], mass[x][y]);
		}
		y = sizeY - 1;
	}
	printf_s("Result:\n");
	for (int i = 0; i < sizeX; i++) {
		for (int y = 0; y < sizeY; y++) {
			printf_s("%4d", mass[i][y]);
		}
		printf_s("\n");
	}
}

void Chtoto() {
	const int sizeX = 5, sizeY = 5;
	int arr[5][5];
	for (int i = 0; i < sizeX; i++) {
		for (int y = 0; y < sizeY; y++) {
			arr[i][y] = rand() % 51 - 25;
			printf_s("%4d", arr[i][y]);
		}
		printf_s("\n");
	}
	printf_s("*work*\n");
	for (int i = 1; i < sizeY; i += 2) {
		int coef = 0;
		for (int h = 0; h < sizeX; h++) {
			if (arr[h][i] < 0) {
				for (int j = h; j > coef; j--) {
					swap(arr[j][i], arr[j - 1][i]);
				}
				coef++;
			}
		}
	}
	for (int i = 0; i < sizeX; i++) {
		for (int y = 0; y < sizeY; y++) {
			printf_s("%4d", arr[i][y]);
		}
		printf_s("\n");
	}
}
