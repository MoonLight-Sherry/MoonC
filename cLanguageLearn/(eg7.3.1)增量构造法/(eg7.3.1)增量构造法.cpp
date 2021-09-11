#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<string.h>

using namespace std;


int B[100];
int A[100];
int C[100]; 
int P[20][10000][20];

void print_subset(int n, int *B, int cur)
{
	if (cur != 0)
	{
		for (int i = 0; i < cur; i++)
		{
			P[cur][C[cur]][i] = A[B[i]];//一维为长度，二维为此长度子集的数量，三维为这个子集是啥
		}
		C[cur]++;
	}
	int s = cur ? B[cur - 1] + 1 : 0;//向后一位
	for (int i = s; i < n; i++)
	{
		B[cur] = i;
		print_subset(n, B, cur + 1);
	}
}

int maino()
{
	int n;
	//freopen("sdf.txt","w",stdout);
	while (scanf_s("%d", &n))
	{
		memset(C, 0, sizeof(C));
		printf("0\n");
		for (int i = 0; i < n; i++)
			A[i] = i + 1;

		print_subset(n, B, 0);

		for (int i = 1; i <= n; i++)
		{
			for (int j = 0; j < C[i]; j++)
			{
				printf("%d ", i);
				for (int k = 0; k < i; k++)
				{
					if (k != i - 1)
						printf("%d ", P[i][j][k]);
					else
						printf("%d", P[i][j][k]);

				}
				printf("\n");
			}
		}
		printf("\n");
	}
	return 0;
}
