#include<stdio.h>
#include<math.h>
#include<windows.h>
int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	double number = 30.50;
	double first, second;
	second = modf(number,&first);
	second *= 100;

	printf_s("%.0f гривень %.0f копійок заплатив Коля, щоб піти на %.0f атракціон“ Колесо огляду ” у парку, для того щоб у %.0f раз подивиться на місто\n", first, second, first, second);
}