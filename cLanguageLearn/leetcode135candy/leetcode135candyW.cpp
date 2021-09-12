#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;


int main()
{
	vector<int> grades,candies;
	int i, j = 0;
	while (scanf_s("%d", &i)) { grades.push_back(i); j++; }
	for (i = 0; i <= j; i++) candies.push_back(i);

	for (i = 1; i <= j; i++)
	{
		if (grades[i] > grades[i - 1]) candies[i] = candies[i-1] + 1;
	}

	for (i = j; i > 0; i--)
	{
		if (grades[i] > grades[i + 1]) candies[i] = candies[i + 1] + 1;
	}

	for (i = 0; i <= j; i++)
	{
		cout << candies[i] << " ";
	}
	return 0;
}














