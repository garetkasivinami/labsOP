#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#pragma region структури
struct pos {
public:
	int x = 0;
	int y = 0;
};
#pragma endregion
#pragma region ідентифікатори
void Task1();
void Task2();
void Task3();
void Task4();
void Self();
void PrintMatrix(int** massive, int lenghtX, int lenghtY) {
	for (int i = 0; i < lenghtX; i++) {
		for (int j = 0; j < lenghtY; j++) {
			printf_s("%3d", massive[i][j]);
		}
		printf_s("\n");
	}
}
#pragma endregion
#pragma region програма
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(0));
	int number;
	while (1) {
		printf_s("Оберіть завдання:\n 1 - завдання 1\n 2 - завдання 2\n 3 - завдання 3\n 4 - завдання 4\n 5 - самостійна\n 0 - вихід\n");
		scanf_s("%d", &number);
		switch (number) {
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
			case 5:
				Self();
				break;
		}
	}
}
#pragma endregion
#pragma region завдання 1
void Task1() {
	int** mass = new int*[4], countNNull = 0;
	for (int i = 0; i < 4; i++) {
		mass[i] = (int*)malloc(3 * sizeof(int));
		for (int j = 0; j < 3; j++) {
			mass[i][j] = i - j;
			if (mass[i][j] != 0) {
				countNNull++;
			}
		}
	}
	printf_s("Сформована матриця:\n");
	PrintMatrix(mass,4,3);
	printf_s("Кількість ненульових елементів %d\n", countNNull);
}
#pragma endregion
#pragma region завдання 2
void Task2() {
	pos size; size.x = 5; size.y = 5;
	int** mass = new int* [size.x];
	for (int i = 0; i < size.x; i++) {
		mass[i] = (int*)malloc(size.y * sizeof(int));
		for (int z = 0; z < size.y; z++) {
			mass[i][z] = -10 + rand() % 21;
		}
	}
	pos maxEl, minEl;
	double* averagLine = (double*)malloc(size.x * sizeof(double));
	printf_s("Сформована матриця:\n");
	PrintMatrix(mass, size.x, size.y);
	for (int i = 0; i < size.x; i++) {
		double average = 0;
		for (int j = 0; j < size.y; j++) {
			if (mass[i][j] > mass[maxEl.x][maxEl.y]) {
				maxEl.x = i;
				maxEl.y = j;
			}
			if (mass[i][j] < mass[minEl.x][minEl.y]) {
				minEl.x = i;
				minEl.y = j;
			}
			average += mass[i][j];
		}
		average /= size.y;
		averagLine[i] = average;
	}
	printf_s("Мінімальний елемент %d, його індекс [%d,%d]\n",mass[minEl.x][minEl.y], minEl.x, minEl.y);
	printf_s("Максимальний елемент %d, його індекс [%d,%d]\n", mass[maxEl.x][maxEl.y], maxEl.x, maxEl.y);
	for (int i = 0; i < size.x; i++) {
		printf_s("Середнє арифметичне %d рядка є %.2f\n",i,averagLine[i]);
	}
	int doubD = 1, summD = 0;
	for (int i = 0; i < size.x && i < size.y; i++) {
		doubD *= mass[i][i];
		summD += mass[i][i];
	}
	printf_s("Добуток елементів головної діагоналі %d, а сума -  %d\n",doubD, summD);
	int summDiadonal = 0;
	for (int i = 1; i < size.x; i++) {
		for (int j = 0; j < i; j++) {
			summDiadonal += mass[i][j];
		}
	}
	printf_s("Сума елементів нижче головної діагоналі %d\n", summDiadonal);
	// щота
}
#pragma endregion
#pragma region завдання 3
void Task3() {
	pos size; size.x = 5; size.y = 5;
	int** mass = new int* [size.x];
	int elements[2] = {0,4};
	for (int i = 0; i < size.x; i++) {
		mass[i] = new int[size.y];
		for (int j = 0; j < size.y; j++) {
			mass[i][j] =  - 10 + rand() % 21;
		}
	}
	printf_s("Сформована матриця:\n");
	PrintMatrix(mass, size.x, size.y);
	printf_s("\n");
	// розширюємо матрцю
	size.y++;
	for (int i = 0; i < size.x; i++) {
		mass[i] = (int*)realloc(mass[i],size.y * sizeof(int));
	}
	// рахуємо
	for (int i = 0; i < size.x; i++) {
		mass[i][size.y - 1] = 0;
		for (int j = 0; j < 2; j++) {
			mass[i][size.y - 1] += mass[elements[j]][i];
		}
	}
	printf_s("Матриця результат:\n");
	PrintMatrix(mass, size.x, size.y);
	free(mass);
}
#pragma endregion
#pragma region завдання 4
void Task4() {
pos size; size.x = 5; size.y = 5;
int** massive = new int* [size.x];
for (int i = 0; i < size.x; i++) {
	massive[i] = new int[size.y];
	for (int z = 0; z < size.y; z++) {
		massive[i][z] = -10 + rand() % 21;
	}
}
printf_s("Сформована матриця:\n");
PrintMatrix(massive,size.x,size.y);
int maxEl = massive[0][0];
printf_s("Elementrs { ");
for (int i = 0; i < size.x; i++) {
	for (int j = 0; j < size.y - i; j++) {
		printf_s("[%d,%d] ", i, j);
		if (massive[i][j] > maxEl) {
			maxEl = massive[i][j];
		}
	}
}
printf_s("}\n");
printf_s("Максимальний елемент %d\n", maxEl);
}
#pragma endregion
#pragma region самостійна
void Self() {
	// створення массиву та заповнення
	pos size; size.x = 6; size.y = 5;
	int** mass = new int* [size.x];
	int temp1 = 0, temp2 = 0;
	for (int i = 0; i < size.x; i++) {
		mass[i] = new int[size.y];
		for (int j = 0; j < size.y; j++) {
			mass[i][j] = 50 + rand() % 20;
		}
	}
	printf_s("*МАТРИЦЯ РЕЗУЛЬТАТІВ*\n");
	PrintMatrix(mass, size.x, size.y);
	// завдання 1
	printf_s("Завдання 1\n");
	int* result = new int[size.y];
	for (int i = 0; i < size.y; i++) {
		result[i] = 0;
	}
	for (int i = 0; i < size.x; i++) {
		for (int j = 0; j < size.y; j++) {
			result[j] += mass[i][j];
		}
	}
	for (int i = 0; i < size.y; i++) {
		printf_s("Загальна кількість голосів за кандидата %d: %d\n", i + 1, result[i]);
	}
	// завдання 2
	printf_s("Завдання 2\n");
	temp1 = 0; temp2 = 0;
	for (int i = 1; i < size.y; i++) {
		if (mass[3][i] > mass[3][temp2]) { // 3 бо числення з нуля
			temp2 = i;
		}
		if (mass[3][i] < mass[3][temp1]) { // 3 бо числення з нуля
			temp1 = i;
		}
	}
	printf_s("Мінімальну кількість голосів в 4 пункті набрав кандидат %d, а максимальну  - %d\n",temp1 + 1, temp2 + 1);
	// завдання 3
	printf_s("Завдання 3\n");
	temp1 = 0;
	for (int i = 0; i < size.x; i++) {
		temp1 += mass[i][0]; // 0 бо з нуля починається
		temp1 += mass[i][2];
	}
	printf_s("Кількість голосів за 1 та 3 кандидата в всіх населених пунктах %d\n", temp1);
	// завдання 4
	printf_s("Завдання 4\n");
	for (int i = 0; i < size.x; i++) {
		int flagF = 0, flagS = 0;
		for (int z = 0; z < size.y; z++) {
			if (mass[i][z] > mass[i][1]) {
				flagF = 1;
			}
			if (mass[i][z] > mass[i][3]) {
				flagS = 1;
			}
		}
		if (!flagF) {
			printf_s("Другий кандидат набрав максимальну кількість голосів у %d пункті\n", i + 1);
		}
		if (!flagS) {
			printf_s("Четвертий кандидат набрав максимальну кількість голосів у %d пункті\n", i + 1);
		}
	}
	// завдання 5
	printf_s("Завдання 5\n");
	int* golozCount = new int[size.x];
	for (int i = 0; i < size.x; i++) {
		int countV = 0;
		for (int z = 0; z < size.y; z++) {
			countV += mass[i][z];
		}
		golozCount[i] = countV;
		printf_s("В %d населеному пункті взяли участь в голосуванні %d людей\n", i + 1, countV);
	}
	// завдання 6
	printf_s("Завдання 6\n");
	temp1 = 0;
	for (int i = 1; i < size.y; i++) {
		if (result[i] > result[temp1]) {
			temp1 = i;
		}
	}
	printf_s("Максимальний рейтинг має кандидат номер %d\n", temp1 + 1);
	// 15 завдання 
	printf_s("Завдання 15\n");
	for (int i = 0; i < size.x; i++) {
		if (golozCount[i] < 450) {
			printf_s("В населеному пункті %d кількість виборців менше 450\n", i+1);
		}
	}
	// 7 завдання
	printf_s("Завдання 7\n");
	for (int i = 0; i < size.x; i++) {
		int flagF = 0;
		for (int z = 0; z < size.y; z++) {
			if (mass[i][z] > mass[i][0]) {
				flagF = 1;
				break;
			}
		}
		if (!flagF) {
			printf_s("Перший кандидат набрав максимальну кількість голосів у %d населеному пункті\n", i + 1);
		}
	}
	// 9 завдання
	printf_s("Завдання 9\n");
	temp2 = 0; 
	for (int i = 1; i < size.x; i++) {
		if (golozCount[i] > golozCount[temp2]) {
			temp2 = i;
		}
	}
	printf_s("Найбільша кількість виборців у %d населеному пункті\n", temp2 + 1);
	// 10 завдання
	printf_s("Завдання 10\n");
	temp1 = 0; temp2 = 0;
	for (int i = 1; i < size.y; i++) {
		if (mass[1][i] > mass[1][temp1]) {// 1 2
			temp1 = i;
		}
		if (mass[2][i] > mass[2][temp2]) {
			temp2 = i;
		}
	}
	printf_s("У 2 населеному пункті найбільшу кількість голосів набрав кандидат %d, а в пункті 3 - %d\n", temp1 + 1, temp2 + 1);
	// 11 завдання
	printf_s("Завдання 11\n");
	temp1 = 0; // min
	temp2 = 0; // max
	for (int i = 1; i < size.x; i++) {
		if (mass[i][0] < mass[1][temp1]) {// 0
			temp1 = i;
		}
		if (mass[i][0] > mass[2][temp2]) {
			temp2 = i;
		}
	}
	printf_s("У %d населеному пункті 1 кандидат набрав мінімальну кількість голосів, а в %d - максимальну\n", temp1 + 1, temp2 + 1);
	
	// 12 завдання 
	printf_s("Завдання 12\n");
	int* elements = new int[3] {1,3,4};// 1 3 4
	int* tempM = new int[3]{0,0,0};
	for (int i = 0; i < size.x; i++) {
		for (int j = 0; j < 3; j++) {
			tempM[j] += mass[i][elements[j]];
		}
	}
	temp1 = 0;
	for (int i = 1; i < 3; i++) {
		if (tempM[i] > tempM[temp1]) {
			temp1 = i;
		}
	}
	printf_s("Серед кандидатів 2,4 та 5 найвищий рейтинг має %d кандидат\n", temp1);
	// 13 завдання
	printf_s("Завдання 13\n");
	temp1 = 0; temp2 = 0;
	for (int i = 0; i < size.x; i++) {
		if (mass[0][i] > mass[0][temp1]) { // max
			temp1 = i;
		}
		if (mass[0][i] < mass[0][temp2]) { // min
			temp2 = i;
		}
	}
	printf_s("Найбільшу кількість голосів у населеному пункті 1 набрав %d кандидат, а найменшу - %d\n", temp1 + 1, temp2 + 1);
	// 14 завдання
	printf_s("Завдання 14\n");
	int belem[2] = {0,4};//new int[2]{0,4}; // 1 5
	for (int i = 0; i < size.x; i++) {
		for (int j = 0; j < 2; j++) {
			if (mass[i][belem[j]] >= 100) {
				printf_s("Кандидат %d набрав більше 100 голосів у %d населеному пункті\n", i + 1, belem[j] + 1);
			}
		}
	}
	// 16 завдання
	printf_s("Завдання 16\n");
	for (int i = 0; i < size.x; i++) {
		temp1 = 0;
		for (int j = 1; j < size.y; j++) {
			if (mass[i][j] < mass[i][temp1]) {
				temp1 = j;
			}
		}
		printf_s("У населеному пункті %d найменшу кількість голосів набрав кандидат %d\n", i + 1, temp1 + 1);
	}
	// 17 завдання
	printf_s("Завдання 17\n");
	belem[0] = 1; // 2 5
	belem[1] = 4;
	for (int i = 0; i < 2; i++) {
		temp1 = 0;
		temp2 = 0;
		for (int j = 0; j < size.y; j++) {
			if (mass[belem[i]][j] > mass[belem[i]][temp1]) { // max
				temp1 = i;
			}
			if (mass[belem[i]][j] < mass[belem[i]][temp2]) { // min
				temp2 = i;
			}
		}
		printf_s("Максимальну кількість голосів у %d населеному пункті набрав кандидат %d, а найменшу - %d\n", belem[i] + 1, temp1 + 1, temp2 + 2);
	}
	printf_s("The end!\n");
	scanf_s("%d", &temp1);
}
#pragma endregion
