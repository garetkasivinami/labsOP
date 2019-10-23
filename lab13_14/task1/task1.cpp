#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <time.h>
#pragma region ідентифікатори
const int sizeInt = sizeof(int);
void createRandomMassive(int* mass, int lenght, int min, int max);
void createRandomAndPrint(int* mass, int lenght, int min, int max);
void printMassive(int* mass, int lenght);
void swap(int& a, int& b);
int random(int min, int max);
void boobleMassiveSort(int* mass, int lenght);
void chooseMethot(int* mass, int lenght);
void pasteMethot(int* mass, int lenght);
void shellaMethot(int* mass, int lenght);
void piramidaMethod(int* mass, int lenght);
void grebinetsMethod(int* mass, int lenght);
void n_boobleMassiveSort(int* mass, int lenght);
void n_chooseMethot(int* mass, int lenght);
void n_pasteMethot(int* mass, int lenght);
void n_shellaMethot(int* mass, int lenght);
void Task1();
void Task2();
void Task3();
void Self();
#pragma endregion
#pragma region програма
int main()
{
	srand(time(0));
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	//Self();
	int target;
	while (1)
	{
		int sizeMass = 20;
		int* massive = new int[sizeMass];
		printf_s("Оберіть завдання:\n 1 - сортування масиву чотирма методами та вивід массиву\n 2 - перевірка швидкості сортування\n 3 - зворотні методи сортування\n 4 - пірамідальний метод сортування\n 5 - метод гребінця\n 0 - вихід\n");
		scanf_s("%d", &target);
		switch (target)
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
			createRandomAndPrint(massive, sizeMass, -50, 50);
			printf_s("Метод піраміди\n");
			piramidaMethod(massive, sizeMass);
			printMassive(massive, sizeMass);
			break;
		case 5:
			createRandomAndPrint(massive, sizeMass, -50, 50);
			printf_s("Метод гребінця\n");
			grebinetsMethod(massive, sizeMass);
			printMassive(massive, sizeMass);
			break;
		default:
			break;
		}
	}
}
#pragma endregion
#pragma region додаткові функції
int random(int min, int max) { // включно максимум
	return (min + rand() % (max - min + 1));
}
void createRandomMassive(int* mass, int lenght, int min, int max) {
	for (int i = 0; i < lenght; i++) {
		mass[i] = random(min,max);
	}
}
void printMassive(int* mass, int lenght) {
	printf_s("{");
	int i = 0;
	while (i < lenght - 1)
	{
		printf("%d, ", mass[i]);
		i++;
	}
	printf_s("%d}\n", mass[i]);
}
void swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}
void createRandomAndPrint(int* mass, int lenght, int min, int max) {
	printf_s("Створенння нового массива...");
	createRandomMassive(mass, lenght, min, max);
	printMassive(mass, lenght);
}
//
void boobleMassiveSort(int* mass, int lenght) {
	int isFalse = 1;
	while (isFalse)
	{
		isFalse = 0;
		for (int i = 1; i < lenght; i++) {
			if (mass[i] < mass[i - 1]) {
				swap(mass[i], mass[i - 1]);
				isFalse = 1;
			}
		}
	}
}
void chooseMethot(int* mass, int lenght) {
	for (int i = 0; i < lenght - 1; i++) {
		int minIndex = i;
		for (int g = i + 1; g < lenght; g++) {
			if (mass[g] < mass[minIndex]) {
				minIndex = g;
			}
		}
		swap(mass[minIndex], mass[i]);
	}

}
void pasteMethot(int* mass, int lenght) {
	for (int i = 1; i < lenght; i++) {
		for (int u = i - 1; u >= 0 && mass[u] > mass[u + 1]; u--) {
			swap(mass[u],mass[u + 1]);
		}
	}
}
void shellaMethot(int* mass, int lenght) {
	int step = lenght / 2;
	while (step > 0)
	{
		for (int i = 0; i < (lenght - step); i++)
		{
			int j = i;
			while (j >= 0 && mass[j] > mass[j + step])
			{
				swap(mass[j], mass[j + step]);
				j--;
			}
		}
		step = step / 2;
	}
}
void piramidaMethod(int* mass, int lenght) {
	int isTrue = 1;
	int zmist = 0;
	while (1) {
		isTrue = 0;
		for (int i = 0; i < lenght / 2; i++) {
			int right = i * 2 + 2 + zmist;
			int left = i * 2 + 1 + zmist;
			int target = i + zmist;
			if (right < lenght) {
				if (mass[target] > mass[left] || mass[target] > mass[right]) {
					if (mass[left] < mass[right])
					{
						swap(mass[target], mass[left]);
						isTrue = 1;
					}
					else if (mass[right] < mass[left])
					{
						swap(mass[target], mass[right]);
						isTrue = 1;
					}
				}
			}
			else if (left < lenght) {
				if (mass[target] > mass[left]) {
					swap(mass[target], mass[left]);
					isTrue = 1;
				}
			}
			else {
				break;
			}
		}
		if (isTrue == 0) {
			zmist++;
			if (zmist + 2 >= lenght) {
				break;
			}
		}
	}
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
//
void n_boobleMassiveSort(int* mass, int lenght) {
	int isFalse = 1;
	while (isFalse)
	{
		isFalse = 0;
		for (int i = 1; i < lenght; i++) {
			if (mass[i] > mass[i - 1]) {
				swap(mass[i], mass[i - 1]);
				isFalse = 1;
			}
		}
	}
}
void n_chooseMethot(int* mass, int lenght) {
	for (int i = 0; i < lenght - 1; i++) {
		int minIndex = i;
		for (int g = i + 1; g < lenght; g++) {
			if (mass[g] > mass[minIndex]) {
				minIndex = g;
			}
		}
		swap(mass[minIndex], mass[i]);
	}

}
void n_pasteMethot(int* mass, int lenght) {
	for (int i = 0; i < lenght; i++) {
		for (int u = i - 1; u >= 0 && mass[u] < mass[u + 1]; u--) {
			swap(mass[u], mass[u + 1]);
		}
	}
}
void n_shellaMethot(int* mass, int lenght) {
	int step = lenght / 2;
	while (step > 0)
	{
		for (int i = 0; i < (lenght - step); i++)
		{
			int j = i;
			while (j >= 0 && mass[j] < mass[j + step])
			{
				swap(mass[j], mass[j + step]);
				j--;
			}
		}
		step = step / 2;
	}
}
#pragma endregion
#pragma region завдання 1
void Task1() {
	int sizeMass = 25;
	int* massive = (int*)malloc(sizeMass * sizeInt);
	//
	createRandomAndPrint(massive, sizeMass, -50, 50);
	printf_s("Бульбашка\n");
	boobleMassiveSort(massive, sizeMass);
	printMassive(massive, sizeMass);
	//
	createRandomAndPrint(massive, sizeMass, -50, 50);
	printf_s("Метод вибору\n");
	chooseMethot(massive, sizeMass);
	printMassive(massive, sizeMass);
	//
	createRandomAndPrint(massive, sizeMass, -50, 50);
	printf_s("Метод вставок\n");
	pasteMethot(massive, sizeMass);
	printMassive(massive, sizeMass);
	//
	createRandomAndPrint(massive, sizeMass, -50, 50);
	printf_s("Метод Шелла\n");
	pasteMethot(massive, sizeMass);
	printMassive(massive, sizeMass);
}
#pragma endregion
#pragma region завдання 2
void Task2() {
	int sizeMass = 10000;
	int* massive = (int*)malloc(sizeMass * sizeInt);
	//
	clock_t start, temp;
	printf_s("Приготувалися....");
	Sleep(3000);
	printf_s("Старт!\n");
	//
	printf_s("Бульбашка!\n");
	start = clock();
	//for (int i = 0; i < 10; i++) {
		createRandomMassive(massive, sizeMass, -500, 500);
		boobleMassiveSort(massive, sizeMass);
	//}
	temp = clock();
	printf_s("Методом бульбашки завдання виконано 10 раз за... %f секунд!!!\n", (float)(temp - start) / CLOCKS_PER_SEC);
	//
	printf_s("Метод вибору\n");
	start = clock();
	//for (int i = 0; i < 10; i++) {
		createRandomMassive(massive, sizeMass, -500, 500);
		chooseMethot(massive, sizeMass);
	//}
	temp = clock();
	printf_s("Методом вибору завдання виконано 10 раз за... %f секунд!!!\n", (float)(temp - start) / CLOCKS_PER_SEC);
	//
	printf_s("Метод вставок\n");
	start = clock();
	//for (int i = 0; i < 10; i++) {
		createRandomMassive(massive, sizeMass, -500, 500);
		pasteMethot(massive, sizeMass);
	//}
	temp = clock();
	printf_s("Методом вставок завдання виконано 10 раз за... %f секунд!!!\n", (float)(temp - start) / CLOCKS_PER_SEC);
	//
	printf_s("Метод Шелла\n");
	start = clock();
	//for (int i = 0; i < 10; i++) {
		createRandomMassive(massive, sizeMass, -500, 500);
		shellaMethot(massive, sizeMass);
	//}
	temp = clock();
	printf_s("Методом Шелла завдання виконано 10 раз за... %f секунд!!!\n", (float)(temp - start) / CLOCKS_PER_SEC);
	//
	free(massive);
}
#pragma endregion
#pragma region завдання 3
void Task3() {
	int sizeMass = random(20, 30);
	int* massive = (int*)malloc(sizeMass * sizeInt);
	//
	createRandomAndPrint(massive, sizeMass, -50, 50);
	printf_s("Бульбашка\n");
	n_boobleMassiveSort(massive, sizeMass);
	printMassive(massive, sizeMass);
	//
	createRandomAndPrint(massive, sizeMass, -50, 50);
	printf_s("Метод вибору\n");
	n_chooseMethot(massive, sizeMass);
	printMassive(massive, sizeMass);
	//
	createRandomAndPrint(massive, sizeMass, -50, 50);
	printf_s("Метод вставок\n");
	n_pasteMethot(massive, sizeMass);
	printMassive(massive, sizeMass);
	//
	createRandomAndPrint(massive, sizeMass, -50, 50);
	printf_s("Метод Шелла\n");
	n_pasteMethot(massive, sizeMass);
	printMassive(massive, sizeMass);
	free(massive);
}
#pragma endregion
void Self() {
	int sizeMass = 50000;
	clock_t start, temp;
	//
	int* massive = new int[50000];
	createRandomMassive(massive, sizeMass, -500, 500);
	start = clock();
	printf_s("Метод вибору\n");
	chooseMethot(massive, sizeMass);
	temp = clock();
	printf_s("Методом вибору завдання виконано 10 раз за... %f секунд!!!\n", (float)(temp - start) / CLOCKS_PER_SEC);
	//
	createRandomMassive(massive, sizeMass, -500, 500);
	start = clock();
	printf_s("Метод Шелла\n");
	shellaMethot(massive, sizeMass);
	temp = clock();
	printf_s("Методом Шелла завдання виконано 10 раз за... %f секунд!!!\n", (float)(temp - start) / CLOCKS_PER_SEC);
	//
	createRandomMassive(massive, sizeMass, -500, 500);
	start = clock();
	printf_s("Метод піраміди\n");
	piramidaMethod(massive, sizeMass);
	temp = clock();
	printf_s("Методом піраміди завдання виконано 10 раз за... %f секунд!!!\n", (float)(temp - start) / CLOCKS_PER_SEC);
	//
	createRandomMassive(massive, sizeMass, -500, 500);
	start = clock();
	printf_s("Метод гребінця\n");
	grebinetsMethod(massive, sizeMass);
	temp = clock();
	printf_s("Методом гребінця завдання виконано 10 раз за... %f секунд!!!\n", (float)(temp - start) / CLOCKS_PER_SEC);
}