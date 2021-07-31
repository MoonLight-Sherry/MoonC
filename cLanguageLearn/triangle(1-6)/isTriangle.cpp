#include "is.h"
#include <stdio.h>

int isTriangle(int a, int b, int c)
{
	if ((a + b) > c && (b + c) > a && (c + a) > b)
	{
		return 1;
	}

	else
	{
		return 0;
	}
}
