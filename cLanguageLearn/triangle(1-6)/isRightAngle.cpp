#include "is.h"
#include <math.h>
#include <stdio.h>

void isRightAngle(int a, int b, int c)
{
	if (a ^ 2 + b ^ 2 == c ^ 2 || b ^ 2 + c ^ 2 == a ^ 2 || c ^ 2 + a ^ 2 == b ^ 2)
		printf("yes");
	else
		printf("no");

}