//#include <stdio.h>
#include <stdio.h>
//#include <cstdio>
#include "freopenTest.h"

using namespace std;

int doubleError()
{
	double i;
	for (i = 0; i != 10; i += 0.1)
		printf("%.1f\n",i);
	return 0;
}