#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
void Swap(int &a, int &b) {
	int temp = a;
	a = b;
	b = temp;
}
void PrintArray(int* Array, int length) {
	printf_s("Array = {");
	for (int i = 0; i < length; i++) {
		printf_s("%d", Array[i]);
		if (i < length - 1) {
			printf_s(", ");
		}
	}
	printf_s("}\n");
}
int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(0));
	int length = 10;
	int* mass = (int*)malloc(length * sizeof(int));
	for (int i = 0; i < length; i++) {
		mass[i] = rand() % 21;
	}
	PrintArray(mass, length);
	int target;
	printf_s("Напишіть число яке потрібно видалити\n");
	scanf_s("%d", &target);
	for (int i = 0; i < length; i++) {
		if (mass[i] == target) {
			if (i < length - 1) {
				for (int j = i + 1; j < length; j++) {
					Swap(mass[j], mass[j - 1]);
				}
			}
			length--;
			i--;
		}
	}
	mass = (int*)realloc(mass,length * sizeof(int));
	PrintArray(mass, length);
}