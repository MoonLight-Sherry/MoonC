//binary tree

#include <cstdio>
#include <cstring>

const int maxd = 20;
int s[1 << maxd];                        //2^(maxd-1)

int main()
{
	int D, I;                            //深度D，小球个数
	while (scanf("%d%d", &D, &I) == 2)
	{
		memset(s, 0, sizeof(s));  
		int k, n = (1 << D) - 1;
		for (int i = 0; i < I; i++) 
		{
			k = 1;
			for (;;)
			{
				s[k] = !s[k];
				k = s[k] ? k * 2 : k * 2 + 1;
				if (k > n) break;       //判断是否出界
			}
		}
		printf("%d", k / 2);
	}
	return 0;
}