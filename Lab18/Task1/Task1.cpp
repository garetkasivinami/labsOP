#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <windows.h>
double Perimeter(double a, double b) {
	return 2 * (a + b);
}
int summMass(int* massive, int length) {
	int result = 0;
	for (int i = 0; i < length; i++) {
		result += massive[i];
	}
	return result;
}
int maxMass(int* massive, int length) {
	int result = 0;
	for (int i = 1; i < length; i++) {
		if (massive[i] > massive[result]) {
			result = i;
		}
	}
	return result;
}
int minMass(int* massive, int length) {
	int result = 0;
	for (int i = 1; i < length; i++) {
		if (massive[i] < massive[result]) {
			result = i;
		}
	}
	return result;
}
int dobMass(int* massive, int length) {
	int result = 1;
	for (int i = 0; i < length; i++) {
		result *= massive[i];
	}
	return result;
}
float Prototype(int a, int b) {
	return a * b;
}
// зачем?
int powToTwo(int number) {
	return pow(number, 2);
}
int reverceNumber(int Number) {
	int result = 0;
	while (Number > 0) {
		result *= 10;
		result += Number % 10;
		Number /= 10;
	}
	return result;
}
int main() {
	srand(time(0));
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	// завдання 1
	double a, b;
	printf_s("Напишіть ширину та висоту прямокутника\n");
	scanf_s("%lf %lf", &a, &b);
	printf_s("Периметер прямокутника %lf\n", Perimeter(a,b));
	// завдання 2
	int length = 10;
	int* massive = new int[length];
	printf_s("масив = {");
	for (int i = 0; i < length; i++) {
		massive[i] = rand() % 21 - 10;
		if (massive[i] == 0) {
			i--;
		}
		printf_s("%d", massive[i]);
		if (i < length - 1) {
			printf_s(", ");
		}
	}
	printf_s("}\n");
	printf_s("Сума елементів масиву %d\n", summMass(massive,length));
	printf_s("Максимальний елемент масива %d\n", maxMass(massive, length));
	printf_s("Мінімальний елемент масива %d\n", minMass(massive, length));
	printf_s("Добуток елементів масива %d\n", dobMass(massive, length));
	// самостійна
	int number;
	printf_s("Напишіть число для розворота ");
	scanf_s("%d", &number);
	printf_s("Розвернене число %d\n", reverceNumber(number));
	return 0;
}