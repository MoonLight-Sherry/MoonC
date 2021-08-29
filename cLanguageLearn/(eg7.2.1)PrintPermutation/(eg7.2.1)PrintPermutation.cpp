#include <iostream>
using namespace std;

int n;
int A[];//序列
int current;//当前要确定的元素位置

void print_permutation(int n, int* A, int cur)
{
	if (cur == n) {
		for (int i = 0; i < n; i++) printf("%d", A[i]);
		printf("\n");
	}
	else for (int i = 0; i < n; i++)
	{
		int ok = 1;
		for (int j = 0; j < cur; j++)
			if (A[j] == i) ok = 0;
		if (ok)
		{
			A[cur] = i;
			print_permutation(n, A, cur + 1);
		}
	}
}

int main()
{
	cin >> n;
}