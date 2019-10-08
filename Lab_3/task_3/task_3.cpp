#include <stdio.h>
#include<math.h>
void firstCalculate();
void secondCalculate();
int main() {
	firstCalculate();
	secondCalculate();
}
void firstCalculate() {
	float a = 1000, b = 0.0001;
	float result = (powf(a - b,2) - (powf(a,2) - 2 * a * b)) / powf(b,2);
	printf_s("%f\n",result);
}
void secondCalculate() {
	double a = 1000, b = 0.0001;
	double result = (pow(a - b, 2) - (pow(a, 2) - 2 * a * b)) / pow(b, 2);
	printf_s("%lf\n", result);
}