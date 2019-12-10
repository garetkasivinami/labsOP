#include <stdio.h>
#include <Windows.h>
#include <time.h>

int main()
{
	int *p;
	int  x=0, y=1, m[10];
	p = &y;
	printf("%d", *p);
	x = *p;

	return 0;
}