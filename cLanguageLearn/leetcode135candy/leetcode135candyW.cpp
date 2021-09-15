#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;


int main()
{
	vector<int> grades, candies;
	int num = 0;
	int ele;
	while (scanf_s("%d", &ele) && ele >= 0) { grades.push_back(ele); num++; }
	//while (scanf_s("%d", &i)) { grades.push_back(i); j++; }

	if (num < 2) { cout << 1; return 0; }

	vector<int> candies(num, 1);
	//for (int i = 0; i < num; i++) candies.push_back(1);

	for (int i = 1; i < num; i++)
	{
		if (grades[i] > grades[i - 1]) candies[i] = candies[i - 1] + 1;
	}

	for (int i = num - 2; i >= 0; i--)
	{
		if (grades[i] > grades[i + 1]) candies[i] = max(candies[i + 1] + 1, candies[i]);
	}

	for (int i = 0; i < num; i++)
	{
		cout << candies[i] << " ";
	}
	return 0;
}

