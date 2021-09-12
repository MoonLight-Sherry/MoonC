//支持a->b,b->c,c->a

#include<iostream>
#include<map>

int N, a, b;

int main()
{
	while (scanf_s("%d", &N) != -1 && N != 0) {
		std::map<int, int> all;

		while (N--) 
		{
			scanf_s("%d%d", &a, &b);
			++all[a], --all[b];
		}

		bool num = false;
		for (const auto &r : all)
			if (r.second) { num = true; break; }

		printf(num ? "NO\n" : "YES\n");
	}
	return 0;
}