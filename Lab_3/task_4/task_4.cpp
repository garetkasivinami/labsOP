#include<stdio.h>
#include<windows.h>
int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int n, m, result;
	printf_s("Введіть два числа через пробіл для розрахунку\n");
	scanf_s("%d %d", &n, &m);
	printf_s("Початкові числа:%d,%d\n", n, m);
	//1
	result = ++m * ++n;
	printf_s("Результат:%d, нові числа %d, %d\n", result, n, m);
	result = (m++ < n);
	printf_s("Результат:%d, нові числа %d, %d\n", result, n, m);
	result = (n++ > ++m);
	printf_s("Результат:%d, нові числа %d, %d\n", result, n, m);
	result =  n++ * m--;
	printf_s("Результат:%d, нові числа %d, %d\n", result, n, m);
	result = (n++<m);
	printf_s("Результат:%d, нові числа %d, %d\n", result, n, m);
	result = (--m > m);
	printf_s("Результат:%d, нові числа %d, %d\n", result, n, m);
	return 0;
}