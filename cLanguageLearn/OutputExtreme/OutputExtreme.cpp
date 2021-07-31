#include <stdio.h>
#include "sort.h"
#define MAX 11
int *pa[MAX];


int main()
{
	int pa[10];
	printf("输入待排序数字");
	for (int i = 0; i <= 9; i++)
	{
		scanf_s("%d", &pa[i]);
	}

	int *left = pa[0];
	int *right = pa[9];


	sort(pa[10], left, right);
	printf("max = %d, min = %d\n", pa[0], pa[9]);
}
