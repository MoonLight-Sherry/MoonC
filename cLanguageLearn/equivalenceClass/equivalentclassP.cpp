// 离线等价类程序
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

vector<vector<int>> sortEquivelentClass(int n, stack<int> relations[]);

int  main()
{
	int n;      // 元素个数
	int r;      // 关系个数

	cout << "Enter number of elements" << endl;
	cin >> n;

	if (n < 2)
	{
		cout << "Too few elements" << endl;
		return 1;           // 因错误而终止
	}

	cout << "Enter number of relations" << endl;
	cin >> r;

	if (r < 1)
	{
		cout << "Too few relations" << endl;
		return 1;           // 因错误而终止
	}

	// 建立空栈组成的数组，stack[0]不用
	stack<int> * relations = new stack<int>[n + 1];

	// 输入r个关系，存储在表中
	int a, b;       // (a, b)是一个关系
	for (int i = 1; i <= r; i++)
	{
		cout << "Enter next relation/pair" << endl;
		cin >> a >> b;
		relations[a].push(b);
		relations[b].push(a);
	}

	vector<vector<int>> equivResults = sortEquivelentClass(n, relations);

	cout << "get results" << endl;

	for (vector<int> result : equivResults)
	{
		for (const int& element : result)
		{
			cout << element << ' ';
		}
		cout << endl;
	}
	

	return 0;
}

vector<vector<int>> sortEquivelentClass(int n, stack<int> relations[])
{


	// 初始化以输出等价类
	stack<int> unprocessedStack;
	vector<vector<int>> results;
	bool *visited = new bool[n + 1];
	for (int i = 1; i <= n; i++)
		visited[i] = false;

	// 输出等价类
	for (int i = 1; i <= n; i++)
	{
		if (!visited[i])
		{
			vector<int> equivResult;


			// 启动一个新类
			cout << "Next class is: " << i << " ";
			visited[i] = true;
			unprocessedStack.push(i);
			equivResult.push_back(i);

			// 从unprocessedList中取类的剩余元素
			while (!unprocessedStack.empty())
			{
				int j = unprocessedStack.top();
				unprocessedStack.pop();

				// 表list[j]中的元素属于同一类
				while (!relations[j].empty())
				{
					int q = relations[j].top();
					relations[j].pop();
					if (!visited[q])     // 未输出
					{
						cout << q << " ";
						equivResult.push_back(q);
						visited[q] = true;

						unprocessedStack.push(q);
					}
				}
			}
			results.push_back(equivResult);
			cout << endl;
		}
	}

	cout << "End of list of equivalence classes" << endl;
	return results;
}