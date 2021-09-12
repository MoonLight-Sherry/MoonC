#include<cstdio>
#include<cstring>

int N, a, b;
int all[1003][1003];//a到b的人数

int main() {
	//freopen("in.txt", "r", stdin);
	while (scanf_s("%d", &N) != -1 && N != 0) {
		memset(all, 0, sizeof(all));

		while (N--)
		{
			scanf_s("%d%d", &a, &b);
			++all[a][b], --all[b][a];
		}

		int *p = all[0], i = 0;
		for (; i < 1006009; ++i, ++p)
			if (*p != 0) break;
		printf(i < 1006009 ? "NO\n" : "YES\n");
	}
	return 0;
}