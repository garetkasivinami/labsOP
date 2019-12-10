#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
void Task1();
void Task2();
void Task3();
void Swap(int&, int&);
void PrintArray(int*, int);
void Self1();
void Self2A();
void Self2B();
void ResizeArr(int* arr, int newLength);
int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(NULL));
	int numb;
	while (1)
	{
		printf_s("Напишіть числа для вибору дороги роботи нашої програми!\n 1 - завдання 1\n 2 - завдання 2\n 3 - завдання 3\n 4 - перший пункт самостійної\n 5 - пунк а другого завдання самостійної\n 6 - другий пункт другого завдання самостійної\n 0 - вихід\n");
		scanf_s("%d", &numb);
		switch (numb)
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
			Self2A();
			break;
		case 6:
			Self2B();
			break;
		default:
			break;
		}
	}
	return 0;
}
void Task1()
{
	int* p;
	// причина появи масива так і залишилася загадкою
	int x = 6, y = 3, * m = (int*)malloc(12 * sizeof(int));
	for (int i = 0; i < 12; i++) {
		m[i] = rand() % 21 - 10;
	}
	p = &y;
	printf_s("%d\n", *p);
	x = *p; // x = y
	y = 7; // *p = 7
	*p += 5; // y = 12
	printf_s("%d\n", *p);
}
void Task2()
{
	int m[12] = { 5,7,8,6,1,2,3,5,4,7,8,5 };
	PrintArray(m, 12);
	int sizeInByte = sizeof(m);// не ну по іншому ніяк
	printf_s("Розмір масива в байтах %d\n", sizeInByte);
	// просто розмір масива
	sizeInByte /= sizeof(int);
	printf_s("Кількість елементів масива %d\n", sizeInByte);
	printf_s("Адреса першого %p та адреса останнього %p\n", &m[0], &m[sizeInByte - 1]);
	for (int i = 0; i < sizeInByte / 2; i++) {
		Swap(m[i], m[sizeInByte - i - 1]);
	}
	PrintArray(m, sizeInByte);
}
void Task3() {
	int length = 15;
	int* arr = (int*)malloc(length * sizeof(int));
	for (int i = 0; i < length; i++) {
		arr[i] = rand() % 8 - 3;
	}
	PrintArray(arr, length);
	for (int i = 0; i < length; i++) {
		if (arr[i] == 0) {
			length--;
			Swap(arr[i], arr[length]);
			arr = (int*)realloc(arr, length * sizeof(int));
		}
	}
	PrintArray(arr, length);
	for (int i = 0; i < length; i++) {
		if (arr[i] % 2 == 0) {
			length++;
			arr = (int*)realloc(arr, length * sizeof(int));
			if (i < length - 2) {
				for (int h = length - 1; h > i + 1; h--) {
					Swap(arr[h], arr[h - 1]);
				}
			}
			arr[i + 1] = arr[i] + 2;
			i++;
		}
	}
	PrintArray(arr, length);
}
void Swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}
void PrintArray(int* arr, int length) {
	printf_s("{");
	for (int i = 0; i < length; i++) {
		printf_s("%d", arr[i]);
		if (i < length - 1) {
			printf_s(", ", arr[i]);
		}
	}
	printf_s("}\n");
}
void Self1() {

	int length = 12;
	int* arr = (int*)malloc(sizeof(int) * length);
	ResizeArr(arr, length);
	for (int i = 0; i < length; i++) {
		arr[i] = rand() % 41 - 20;
	}
	PrintArray(arr, length);
	for (int i = 0; i < length; i += 2) {
		Swap(arr[i], arr[i + 1]);
	}
	PrintArray(arr, length);
}
void Self2A() {
	int sizeA = 15, sizeB = 9;
	int* a = (int*)malloc(sizeA * sizeof(int)), * b = (int*)malloc(sizeB * sizeof(int));
	for (int i = 0; i < sizeA; i++) {
		a[i] = rand() % 41 - 20;
	}
	for (int i = 0; i < sizeB; i++) {
		b[i] = rand() % 41 - 20;
	}
	PrintArray(a, sizeA);
	PrintArray(b, sizeB);
	int newSize = sizeA + sizeB;
	int* arr1 = (int*)malloc(sizeof(int) * (sizeA + sizeB));
	int* g = arr1;
	for (int i = 0; i < sizeA; i++) {
		*g = a[i];
		g++;
	}
	for (int i = 0; i < sizeB; i++) {
		*g = b[i];
		g++;
	}
	PrintArray(arr1, newSize);
}
void Self2B() {
	int sizeA = 5, sizeB = 6;
	int* a = (int*)malloc(sizeA * sizeof(int)), * b = (int*)malloc(sizeB * sizeof(int));
	for (int i = 0; i < sizeA; i++) {
		a[i] = rand() % 41 - 20;
	}
	for (int i = 0; i < sizeB; i++) {
		b[i] = rand() % 41 - 20;
	}
	PrintArray(a, sizeA);
	PrintArray(b, sizeB);
	int Length = 0;
	int flag = 1;
	//int* arr = (int*)malloc(0);
	int* arr = (int*)malloc(sizeA > sizeB? sizeA: sizeB);
	for (int i = 0; i < sizeA; i++) {
		/*if (sizeB == 0) {
			break;
		}*/
		for (int j = 0; j < sizeB; j++) {
			if (a[i] == b[j]) {
				/*ResizeArr(arr, Length + 1);
				arr[Length] = a[i];
				Length++;
				Swap(b[j], b[sizeB - 1]);
				sizeB--;
				ResizeArr(b, sizeB);
				j--;*/
				for (int z = 0; z < Length; z++) {
					if (arr[z] == a[z]) {
						flag = 0;
						break;
					}
				}
				if (flag) {
					arr[Length] = a[i];
					Length++;
				}
			}
		}
	}
	ResizeArr(arr, Length);
	PrintArray(arr, Length);
}

void ResizeArr(int* arr, int newLength) {
	arr = (int*)realloc(arr, newLength * sizeof(int));
}