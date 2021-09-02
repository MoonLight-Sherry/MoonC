#include <cstdio>
#include <stack>

using namespace std;

const int MAXN = 1000 + 10;

int n, target[MAXN];

int main()
{
	while (scanf_s("%d", &n) == 1)
	{
		stack<int> s;
		int A = 1, B = 1;
		for (int i = 1; i <= n; i++)
			scanf_s("%d", &target[i]);
		int ok = 1;
		while (B <= n)
		{
			if (A == target[B]) { A++; B++; }//处理第一个目标数字为1的情况
			else if (!s.empty() && s.top() == target[B]) { s.pop(); B++; }
			else if (A <= n) s.push(A++);
			else { ok = 0; break; }
		}
		printf("%s\n", ok ? "yes" : "no");
	}
	return 0;
}












