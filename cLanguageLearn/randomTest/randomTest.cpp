#include <cstdlib>//包含rand()
#include <vector>
#include <algorithm>
#include <cassert>
#include <iostream>
#include <ctime>

using namespace std;

void fill_random_int(vector<int>& v, int cnt)
{
	v.clear();
	for (int i = 0; i <= cnt; i++)
		v.push_back(rand());
}

void test_sort(vector<int>& v)
{
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size() - 1; i++)
		assert(v[i] <= v[i + 1]);
}

int main()
{
	vector<int> v;
	srand(time(NULL));//若无，自动调用strand(1)
	fill_random_int(v, 100);
	test_sort(v);
	for (int i = 0; i < v.size() - 1; i++)
		cout << v[i] << endl;
	return 0;
 }