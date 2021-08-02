#include <stdio.h>

int main(void)
{
	int a, b;
	printf("input a,b\n");
	scanf_s("%d%d", &a, &b);
	printf("%d\n", a+b);
	return 0;
}