#include<stdio.h>
#include<math.h>
#include<windows.h>
#include "myMath.h"

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	vector3 point;
	while (true) {
		printf_s("Введіть позиції(3 шт.) точки через пробіл\n");
		scanf_s("%lf %lf %lf", &point.x, &point.y, &point.z);
		CheckPos3(point);
		printf_s("Для виходу напишіть 0\n Інше число для продовження\n");
		int data = 0;
		scanf_s("%d",&data);
		if (data == 0) {
			return 0;
		}
	}
}
