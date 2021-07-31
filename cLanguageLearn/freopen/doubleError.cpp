#include<stdio.h>
#include "freopenTest.h"

int doubleError()
{
	double i;
	for (i = 0; i != 10; i += 0.1)
		printf("%.1f\n",i);
	return 0;
}