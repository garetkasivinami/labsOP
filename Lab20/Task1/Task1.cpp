#include <stdio.h>
#include <math.h>
#include <windows.h>
#include <time.h>
#include <stdio.h>

#pragma region Ідентифікатори
void PrintMassive(int*, int, int);
void PrintMassive(int* arr, int n);
int MaxInArray(int*, int, int);
int MaxInArray(int*, int);
int MinInArray(int*, int, int);
int MinInArray(int*, int);
int SumArray(int*, int, int);
int SumArray(int*, int);
int AverageElementArr(int*, int, int);
double AverageElementArr(int*, int);
//
int NumberToSystemRec(int, int);
long NumberToSystem(int, int);
int MaxHalfMethodRec(int*, int, int, int);
double RachunokRec(int, int);
double Rachunok(int);
int Fact(int);
double ResultOfSummRec(int);
double ResultOfSumm(int);
//
int ReverceNumber(int, int);
int NumberPalindrop(int);
double Dobytok(double);
double KakaitoFunctia(double, int);
int CountNumbers(int);
void PrintNumber(int);
#pragma endregion

void main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	/*int length = 10;
	int* arr = new int[10];
	for (int i = 0; i < length; i++) {
		arr[i] = rand() % 21 - 10;
		if (arr[i] == 0) {
			i--;
		}
	}
	printf_s("Массив сформований для експериментів:\n");
	printf_s("{");
	PrintMassive(arr, length);
	printf_s("}\n");
	printf_s("Максимальний елемент масива %d\n", MaxInArray(arr, length));
	printf_s("Мінімальний елемент масива %d\n", MinInArray(arr, length));
	printf_s("Сума елементів масива %d\n", SumArray(arr, length));
	printf_s("Середнє арифметичне значення масива %g\n", AverageElementArr(arr, length));*/
	// 2 завдання
	int number, sys;
	//printf_s("Напишіть число(ціле) та систему числення (2 - 9) в яку треба його перевести\n");
	//scanf_s("%d %d", &number, &sys);
	//printf_s("%d в %d системі числення це %d\n",number,sys,NumberToSystemRec(number, sys));
	//printf_s("Для пошуку будемо використовувати наш минулий масив\n");
	//printf_s("Максимальний елемент масива %d\n", MaxHalfMethodRec(arr, length,0, length));
	printf_s("Напишіть число для розрахунку\n");
	scanf_s("%d", &number);
	printf_s("%lf (рекурсія) або %lf (без рекурсії)\n", RachunokRec(1, number), Rachunok(number));
	/*printf_s("Напишіть число для розрахунку суми\n");
	scanf_s("%d", &number);
	printf_s("%lf (рекурсія) або %lf (без рекурсії)", ResultOfSummRec(number), ResultOfSumm(number));*/
	// самостійна
	/*printf_s("Блок самостійної роботи\n");
	printf_s("Напишіть число для перевірки на паліндром(?)\n");
	scanf_s("%d", &number);
	NumberPalindrop(number) ? printf_s("Це число є паліндропом\n"): printf_s("Це число не є паліндропом\n");
	printf_s("Якийсь там добуток становить %lf\n", Dobytok(2));
	printf_s("Напишіть число та степінь(цілий більше одиниці) для його розрахунку y=x^n\n");
	scanf_s("%d %d", &number, &sys);
	printf("%d ^ %d = %lf\n", number, sys, KakaitoFunctia(number, sys));
	printf_s("Напишіть число для розрахунку кільксоті цифр в ньому\n");
	scanf_s("%d", &number);
	printf_s("%d має %d цифр\n", number, CountNumbers(number));
	printf_s("Напишіть число, щоб вивести його в зворотньому порядку по рядках\n");
	scanf_s("%d", &number);
	PrintNumber(number);*/
}

#pragma region завдання 1
void PrintMassive(int* arr, int lenght, int i) {
	printf_s("%d",arr[i]);
	if (i < lenght - 1) {
		printf_s(", ");
		PrintMassive(arr, lenght, i + 1);
	}
}
void PrintMassive(int* arr, int n) {
	n--;
	if (n > 0) {
		PrintMassive(arr, n);
		printf_s(", ");
	}
	printf_s("%d", arr[n]);
}
int MaxInArray(int *arr, int lenght, int i) {
	if (i == lenght - 1) {
		return arr[i];
	}
	int maxUp = MaxInArray(arr, lenght, i + 1);
	return (maxUp > arr[i]) ? maxUp: arr[i];
}
int MaxInArray(int* arr, int n) {
	n--;
	if (n == 0){
		return arr[n];
	}
	int maxUp = MaxInArray(arr, n);
	return (maxUp > arr[n]) ? maxUp : arr[n];
}
int MinInArray(int* arr, int lenght, int i) {
	if (i == lenght - 1) {
		return arr[i];
	}
	int maxUp = MaxInArray(arr, lenght, i + 1);
	return (maxUp < arr[i]) ? maxUp : arr[i];
}
int MinInArray(int* arr, int n) {
	n--;
	if (n == 0) {
		return arr[n];
	}
	int minUp = MinInArray(arr, n);
	return (minUp < arr[n]) ? minUp : arr[n];
}
int SumArray(int* arr, int lenght, int i) {
	if (i == lenght - 1) {
		return arr[i];
	}
	return arr[i] + SumArray(arr, lenght, i + 1);
}
int SumArray(int* arr, int n) {
	n--;
	if (n == 0) {
		return arr[0];
	}
	return arr[n] + SumArray(arr, n);
}
int AverageElementArr(int* arr, int length, int i) {
	if (i == length - 1) {
		return arr[i] / length;
	}
	return arr[i] / length + AverageElementArr(arr,length, i + 1);
}
double AverageElementArr(int* arr, int length) {
	return (double)SumArray(arr, length) / length;
}
#pragma endregion
#pragma region завдання 2
int NumberToSystemRec(int number, int p) {
	if (number < p) {
		return number;
	}
	return (number % p) + NumberToSystemRec(number / p, p) * 10;
}
long NumberToSystem(int number, int p) {
	int result = 0;
	for (int i = 0; number > 0; i++) {
		result += (number % p) * pow(10,i);
		number /= p;
	}
	return result;
}
int MaxHalfMethodRec(int* arr, int length, int i, int cLength) {
	int a, b;
	if (cLength == 2) {
		a = arr[i];
		b = arr[i + 1];
	}
	else {
		a = MaxHalfMethodRec(arr, length, i, cLength / 2 + cLength % 2);
		b = MaxHalfMethodRec(arr, length, i + cLength / 2, cLength / 2 + cLength % 2);
	}
	return a > b ? a: b;
}
double RachunokRec(int k, int n) {
	if (k == n) {
		return sqrt(n);
	}
	return sqrt(k + RachunokRec(k + 1, n));
}
double Rachunok(int n) {
	double result = 0;
	for (int i = n; i > 0; i--) {
		result = sqrt(i + result);
	}
	return result;
}
int Fact(int n) {
	if (n == 1) {
		return 1;
	}
	return n * Fact(n - 1);
}
double ResultOfSummRec(int n) {
	if (n == 1) {
		return 1;
	}
	return 1.0 / Fact(n) + ResultOfSummRec(n - 1);
}
double ResultOfSumm(int n) {
	double result = 0;
	for (int i = 1; i <= n; i++) {
		result += 1.0 / Fact(i);
	}
	return result;
}
#pragma endregion
#pragma region Self
int ReverceNumber(int number, int coef) {
	if (number) {
		return ReverceNumber(number / 10, coef * 10 + number % 10);
	}
	return coef;
}
int NumberPalindrop(int number) {
	return number == ReverceNumber(number, 0);
}
double Dobytok(double coef) {
	if (coef > 1000) {
		return 1;
	}
	return pow(coef, 2) / ((coef - 1) * (coef + 1)) * Dobytok(coef + 2);
}
double KakaitoFunctia(double number, int step) {
	if (step == 0) {
		return 1;
	}
	if (step % 2 == 0) {
		return pow(KakaitoFunctia(number, step / 2),2);
	}
	else {
		return number * KakaitoFunctia(number, step - 1);
	}
}
int CountNumbers(int number) {
	if (number == 0) {
		return 0;
	}
	return 1 + CountNumbers(number / 10);
}
void PrintNumber(int number) {
	if (number > 0) {
		printf_s("%d\n", number % 10);
		PrintNumber(number / 10);
	}
}
#pragma endregion