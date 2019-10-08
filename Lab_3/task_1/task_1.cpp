#include<stdio.h>
int main() {
	int first = 6;
	int second = 5;
	printf_s("|%d%d%-5d|%5d%d%d|\n", second, second, second, second, second, second);
	printf_s("|%d%d%-5d|%d%d%-5d|\n", first, first, first, second, second, second);
	printf_s("|%5d%d%d|%d%d%-5d|\n", first, first, first, first, first, first);
	printf_s("|%5d%d%d|%5d%d%d|\n", second, second, second,first,first,first);
}