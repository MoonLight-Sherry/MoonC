#include <stdio.h>
#include "sort.h"

#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	const int MAX = 11;
	int pa[MAX];

	ifstream thisSource("");

	printf("输入待排序数字input");
	for (int i = 0; i <= 9; i++)
	{
		scanf_s("%d", &pa[i]);
	}

	int * left = &pa[0];
	int * right = pa + 9;


	sort(pa, left, right);
	printf("max = %d, min = %d\n", pa[0], pa[9]);
}
