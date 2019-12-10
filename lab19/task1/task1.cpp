#define _USE_MATH_DEFINES
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <Windows.h>
#include <time.h>
#pragma region завдання 1
char ukrGolos[] = {'а','и','і','у','е','о'};
char resultOperation(int a, int b) {
	if (a > b) {
		return '>';
	}
	else if (a < b) {
		return '<';
	}
	else {
		return '=';
	}
}
float Procent(float number, float procent) {
	return number * procent;
}
double vklad(double salary, double percent, int days) {
	return salary * percent * (days / 365.0);
}
int isUkrGolos(char a) {
	for (int i = 0; i < 6; i++) {
		if (a == ukrGolos[i]) {
			return 1;
		}
	}
	return 0;
}
char GetZnak(int number) {
	if (number >= 0) {
		return '+';
	}
	else {
		return '-';
	}
}
void printZirka(int count) {
	for (int i = 0; i < count; i++) {
		printf_s("*");
	}
	printf_s("\n");
}
void WriteAverage(int count, double* numbers) {
	double result = 0;
	for (int i = 0;i < count; i++) {
		result += numbers[i];
	}
	result /= count;
	printf_s("Середнє арифметичне ряду чисел %f\n", result);
}
// ось тут і рекурсія приїхала
int getFactorial(int number) {
	if (number <= 1) {
		return 1;
	}
	return number * getFactorial(number - 1);
}
void Task1() {
	//1
	int a = rand() % 20, b = rand() % 20;
	printf_s("%d %c %d\n", a, resultOperation(a, b), b);
	//2
	float number = rand() % 100, procent = (float)rand() / RAND_MAX;
	printf_s("%.3f відсотків від %f становить %f\n",procent * 100, number, Procent(number, procent));
	//3
	number = rand() % 2000 + 2000, procent = (float)rand() / RAND_MAX;
	int days = rand() % 1000 + 365;
	printf_s("Початкова сума %.2f, відсоток %.2f, кількість днів %d. Результат %lf\n", number, procent * 100, days, vklad(number,procent,days));
	// 4 
	char sumvol;
	printf_s("Напишіть символ\n");
	scanf_s(" %c", &sumvol);
	(isUkrGolos(sumvol)) ? printf_s("Це голосна літера українського алфавіта\n"): printf_s("Це НЕ голосна літера українського алфавіта\n");
	// 5 
	printf_s("Напишіть будь-яке ціле число\n");
	scanf_s("%d", &a);
	printf_s("Це число є %c\n",GetZnak(a));
	// 6 
	printf_s("Напишіть кількість зірочок\n");
	scanf_s("%d", &a);
	printZirka(a);
	// 7 
	int length = rand() % 20 + 5;
	double* numbers = new double[length];
	printf_s("numbers = {");
	for (int i = 0; i < length; i++) {
		numbers[i] = rand() % 20 - 10 + (float)rand() / RAND_MAX;
		printf_s("%.3f", numbers[i]);
		if (i != length - 1) {
			printf_s(", ");
		}
	}
	printf_s("}\n");
	WriteAverage(length, numbers);
	// 8
	printf_s("Напишіть число для обчислення факторіла (> 1)\n");
	scanf_s("%d", &a);
	printf_s("Факторіал числа %d становить %d", a, getFactorial(a));
}
#pragma endregion
#pragma region завдання 2
void ToPowTwo(int* elements, int lenght) {
	for (int i = 0; i < lenght; i += 2) {
		if (elements[i] < 0) {
			elements[i] = pow(elements[i],2);
		}
	}
}
// дискримінант є ссилкою
int GetSqrtRivnannya(int a, int b, int c, double &discriminant) {
	if (a == 0) {
		return 1;
	}
	discriminant = pow(b, 2) - 4 * a * c;
	if (discriminant > 0) {
		return 2;
	}
	else if (discriminant < 0) {
		return 0;
	}
	else {
		return 1;
	}
}
void Kratne7(int* massive) {
	for (int i = 1; i <= 10; i++) {
		massive[i - 1] = 7 * i;
	}
}
void swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}
void fswap(float& a, float& b) {
	float temp = a;
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
void sortByAbs(int* mass, int lenght) {
	int flag = 1;
	int gap = lenght;
	while (flag || gap > 1) {
		flag = 0;
		gap = newGap(gap);
		for (int i = 0; i < lenght - gap; i++) {
			if (abs(mass[i + gap]) < abs(mass[i])) {
				swap(mass[i + gap], mass[i]);
				flag = 1;
			}
		}
	}
}
void sortByAbs(float* mass, int lenght) {
	int flag = 1;
	int gap = lenght;
	while (flag || gap > 1) {
		flag = 0;
		gap = newGap(gap);
		for (int i = 0; i < lenght - gap; i++) {
			if (fabs(mass[i + gap]) < fabs(mass[i])) {
				fswap(mass[i + gap], mass[i]);
				flag = 1;
			}
		}
	}
}
void ChotoDelat(float* massive, int length) {
	for (int i = 0; i < length; i++) {
		if (massive[i] >= 0 && massive[i] <= 3) {
			massive[i] *= 3;
		} else if (fabs(massive[i]) > 7) {
			massive[i] -= 2;
		}
	}
}
int IfNumbersRepeated(int* mass, int length) {
	for (int i = 0; i < length - 1; i++) {
		for (int j = i + 1; j < length; j++) {
			if (mass[i] == mass[j]) {
				return 1;
			}
		}
	}
	return 0;
}
int deleteNumbersAreLess(int* massive, int lenght, int number) {
	int newLength = 0;
	for (int i = 0; i < lenght; i++) {
		if (i >= number) {
			massive[newLength] = massive[i];
			newLength++;
		}
	}
	if (newLength < lenght) {
		int max = massive[newLength];
		for (int i = newLength; i < lenght; i++) {
			if (massive[i] > max) {
				max = massive[i];
			}
		}
		printf_s("Максимальний видалений елемент масива %d\n", max);
	}
	massive = (int*)realloc(massive, sizeof(int) * newLength);
	return newLength;
}
void PrintArray(int* _array, int length) {
	printf_s("array = {");
	for (int i = 0; i < length; i++) {
		printf_s("%d", _array[i]);
		if (i != length - 1) {
			printf_s(", ");
		}
	}
	printf_s("}\n");
}
void PrintArrayF(float* _array, int length) {
	printf_s("array = {");
	for (int i = 0; i < length; i++) {
		printf_s("%.2f", _array[i]);
		if (i != length - 1) {
			printf_s(", ");
		}
	}
	printf_s("}\n");
}
void Task2() {
	//1
	int length = 10;
	int* intMass = new int[length];
	for (int i = 0; i < length; i++) {
		intMass[i] = rand() % 21 - 10;
	}
	PrintArray(intMass, length);
	printf("Піднесення до квадрату індексів з непарними елементами та які менше нуля\n");
	ToPowTwo(intMass,length);
	PrintArray(intMass, length);
	//2
	double a, b, c, Disc = 0;
	printf_s("Напишіть коефіцієнти рівняння\n ax^2+bc+c = 0\n");
	scanf_s("%lf%lf%lf", &a, &b, &c);
	printf_s("Рівнняня має %d коренів. дискримінант рівнняня %d\n", GetSqrtRivnannya(a,b,c,Disc), Disc);
	//3
	Kratne7(intMass);
	PrintArray(intMass, length);
	//4
	printf_s("Масив для сортування\n");
	for (int i = 0; i < length; i++) {
		intMass[i] = rand() % 21 - 10;
	}
	PrintArray(intMass, length);
	printf_s("Масив після сортування\n");
	sortByAbs(intMass, length);
	PrintArray(intMass, length);
	// 5
	float* arrayFloat = new float[length];
	printf_s("Масив для сортування\n");
	for (int i = 0; i < length; i++) {
		arrayFloat[i] = rand() % 20 - 10 + (float)rand() / RAND_MAX;
	}
	PrintArrayF(arrayFloat, length);
	printf_s("Масив після сортування\n");
	sortByAbs(arrayFloat, length);
	PrintArrayF(arrayFloat, length);
	// 6 
	printf_s("Будемо використовувати відсортований масив з минулого завдання\n");
	ChotoDelat(arrayFloat, length);
	PrintArrayF(arrayFloat, length);
	// 7
	PrintArray(intMass, length);
	int result = IfNumbersRepeated(intMass, length);
	if (result) {
		printf_s("масив має елементи, які повторюються\n");
	} else{
		printf_s("масив не має елементів, які повторюються\n");
	}
	//8
	int l;
	for (int i = 0; i < length; i++) {
		intMass[i] = rand() % 21 - 10;
	}
	PrintArray(intMass, length);
	printf_s("Напишіть бажане вами число\n");
	scanf_s("%d", &l);
	int newLenght = deleteNumbersAreLess(intMass,length, l);
	PrintArray(intMass, newLenght);
}
#pragma endregion
#pragma region завдання 3
void Swap(int &a, int &b) {
	int temp = a;
	a = b;
	a = temp;
}
void minMax(int &a, int &b) {
	if (a > b) {
		swap(a,b);
	}
}
void SortInc3(int A, int B, int C) {
	minMax(B, C);
	minMax(A, B);
	minMax(B, C);
}
void SortDec3(int A, int B, int C) {
	minMax(B, A);
	minMax(C, B);
	minMax(B, A);
}
void ShiftRight(int A, int B, int C) {
	swap(A, B);
	swap(B,C);
}
void ShiftLeft(int A, int B, int C) {
	swap(A,B);
	swap(A,C);
}
int ChtotoEsho(double* massive, int length, int &count) {
	count = 0;
	for (int i = 0; i < length; i++) {
		if ((int)massive[i] == massive[i] && (int)massive[i] % 3 == 0) {
			count++;
		}
	}
	return (count == 0) ? 0 : 1;
}
void zamena(int* massive, int length, int number) {
	massive[length / 2] = number;
}
void Task3() {
	int a, b, c, d;
	// завдання 1 не потребує написання кода
	// 2
	printf_s("Напишіть чотири числа для пошуку найменшого та найбільшого\n");
	scanf_s("%d%d%d%d",&a,&b,&c,&d);
	minMax(a, b);
	minMax(c,d);
	minMax(a,c);
	minMax(b,d);
	printf_s("Мінімальне число %d, а максимальне число %d\n", a, d);
	// 3
	printf_s("Напишіть три числа для впорядкування за зростанням\n");
	scanf_s("%d%d%d", &a, &b, &c);
	SortInc3(a,b,c);
	printf_s("Впорядковані за зростанням числа %d, %d, %d\n", a,b,c);
	// 4
	printf_s("Напишіть три числа для впорядкування за спаданням\n");
	scanf_s("%d%d%d", &a, &b, &c);
	SortDec3(a, b, c);
	printf_s("Впорядковані за спаданням числа %d, %d, %d\n", a, b, c);
	//5 
	printf_s("Напишіть три числа для зсуву вправо\n");
	scanf_s("%d%d%d", &a, &b, &c);
	ShiftRight(a, b, c);
	printf_s("Числа після зсуву вправо %d, %d, %d\n", a, b, c);
	//6
	printf_s("Напишіть три числа для зсуву вліво\n");
	scanf_s("%d%d%d", &a, &b, &c);
	ShiftLeft(a, b, c);
	printf_s("Числа після зсуву вліво %d, %d, %d\n", a, b, c);
}
#pragma endregion
#pragma region завдання 4
int Sign(int x) {
	if (x < 0) {
		return -1;
	}
	else if (x > 0) {
		return 1;
	}
	else {
		return 0;
	}
}
double TriangleP(double a, double h) {
	return 2 * sqrt(pow(a / 2, 2) + pow(h, 2)) + a;
}
double Calc(double a, double b, int operation) {
	switch (operation)
	{
	case 1:
		return a - b;
	case 2:
		return a * b;
	case 3:
		return a / b;
	default:
		return a + b;
	}
}
int Quarter(double x, double y) {
	if (x >= 0) {
		if (y >= 0) {
			return 1;
		}
		else {
			return 4;
		}
	}
	else {
		if (y >= 0) {
			return 2;
		}
		else {
			return 3;
		}
	}
}
int DigitCount(int k) {
	int counter = 0;
	while (k > 0) {
		counter++;
		k /= 10;
	}
	return counter;
}
int DigitCount(int k, int N) {
	int counter = 0;
	while (k > 0) {
		counter++;
		if (counter == N) {
			return k % 10;
		}
		k /= 10;
	}
	return 1;
}
double DegToRad(double d) {
	return d /180 * M_PI;
}
double RadToDeg(double r) {
	return r / M_PI * 180;
}
int Fib(int N) {
	int result = 1;
	int temp;
	int tempNumber = 1;
	if (N < 3) {
		return 1;
	}
	for (int i = 2; i < N; i++) {
		temp = tempNumber;
		tempNumber = result;
		result += temp;
	}
	return result;
}
void Task4() {
	// 1
	double a, b;
	int op;
	printf_s("Напишіть два числа для розрахунку ф-ії\n");
	scanf_s("%lf%lf", &a, &b);
	printf_s("Результат %d\n", Sign(a) + Sign(b));
	// 2
	printf_s("Напишіть сторону та висоту проведену до неї\n");
	scanf_s("%lf%lf", &a, &b);
	printf_s("периметер цього трикутника %lf\n", TriangleP(a,b));
	// 3
	printf_s("Напишіть два числа та операцію над ними\n");
	printf_s("Операції: 1 - віднімання, 2 - множення, 3 - ділення, інше число - додавання\n");
	scanf_s("%lf%lf%d", &a, &b, &op);
	printf_s("Результат розрахунків %lf\n", Calc(a, b, op));
	// 4
	printf_s("Напишіть дві координати дл визначення координатної чверті, в якій вони лежать\n");
	scanf_s("%lf%lf", &a, &b);
	printf_s("Точка належить до %d координатної чверті\n", Quarter(a,b));
	// 5
	printf_s("Напишіть додатнє число для визначення кількості чисел\n");
	scanf_s("%d", &op);
	printf_s("Кількість чисел в числі - %d\n", DigitCount(op));
	// 6
	int number;
	printf_s("Напишіть додатнє число для визначення кількості чисел та номер цифри, яка потрібна\n");
	scanf_s("%d%d", &op, &number);
	printf_s("Цифра - %d\n", DigitCount(op, number));
	// 7 
	printf_s("Оберіть режим:\n 1 - deg to rad\n 2 - rad to deg\n");
	scanf_s("%d", &op);
	if (op == 1) {
		printf_s("Напишіть градус для перетворення в радіани\n");
		scanf_s("%lf", &a);
		printf_s("Градус в радіанах %lf\n", DegToRad(a));
	}
	else {
		printf_s("Напишіть радіани для перетворення в градуси\n");
		scanf_s("%lf", &a);
		printf_s("Радіани в градусах %lf\n", RadToDeg(a));
	}
	// 8 
	printf_s("Напишіть число для визначення числа фібоначі\n");
	scanf_s("%d", &op);
	printf_s("Число фібоначі - %d\n", Fib(op));
}
#pragma endregion
#pragma region самостійна
void TaskSelf() {

}
double Leng(double xA,double yA,double xB, double yB) {
	return sqrt(pow(xB - xA,2) + pow(yB - yA, 2));
}
double Perim(double xA, double yA, double xB, double yB, double xC, double yC) {
	return Leng(xA, yA, xB, yB) + Leng(xB, yB, xC, yC) + Leng(xA, yA, xC, yC);
}
double Area(double xA, double yA, double xB, double yB, double xC, double yC) {
	double perim = Perim(xA,yA,xB,yB,xC,yC) / 2;
	return sqrt(perim * (perim - Leng(xA,yA,xB,yB)) * (perim - Leng(xB,yB,xC,yC)) * (perim - Leng(xC,yC,xA,yA)));
}
double Dist(double xP, double yP, double xA, double yA, double xB, double yB) {
	return 2 * Area(xP, yP, xA, yA, xB, yB) / Leng(xA,yA,xB,yB);
}
void Altitudes(double xA, double yA, double xB, double yB, double xC, double yC, double &hA, double &hB, double &hC) {
	hA = Dist(xA, yA, xB, yB, xC, yC);
	hB = Dist(xB, yB, xA, yA, xC, yC);
	hC = Dist(xC, yC, xB, yB, xA, yA);
}
void Self() {
	double xa, ya, xb, yb, xc, yc;
	// 
}
#pragma endregion
// ось і наша програмка
int main() {
	srand(time(0));
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Task2();
	return 0;
}