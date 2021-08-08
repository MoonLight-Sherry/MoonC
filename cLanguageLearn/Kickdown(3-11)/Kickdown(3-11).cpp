#include <iostream>
#define Max(a,b) ((a>b)? (a):(b))
#define Min(a,b) ((a<b)? (a):(b))

using namespace std;

int main()
{
	int a1[105];
	int a2[105];
	int n1 = 0;
	int n2 = 0;
	char c;
	int p = 0,q = 0;
	int temp;

	while ((c = getchar()) != '\n')
	{
		cin >> a1[p++];//怎么输入单个数字？
	}

	while ((c = getchar()) != '\n')
	{
		cin >> a2[q++];
	}

	for (int i = 0; i <= (p, q); i++)
	{
		for (int j = 0; j <= Min(n1, (n2 + i)); j++)
		{
			if (a1[j + i] == 2 & a2[j] == 2)
				continue;
			if (j == Max(n1,(n2 +i)))
				cout << j;
		}
	}

	return 0;
}
