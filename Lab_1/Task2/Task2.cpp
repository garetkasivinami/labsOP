#include <windows.h>
#include <stdio.h>

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	char japan[] = "«Прозрачный водопад»…\nУпала в светлую волну\nСосновая игла.";
	printf_s(japan);
	return 0;
}