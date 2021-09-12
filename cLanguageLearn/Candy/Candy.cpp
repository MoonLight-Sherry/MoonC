// Candy.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>



#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;


int main()
{
	vector<int> grades, candies;
	int ele;
	int num = 0;
	while (scanf_s("%d", &ele) && ele >= 0) { grades.push_back(ele); num++; }
	for (int i = 0; i < num; i++) candies.push_back(i);

	for (int i = 1; i < num; i++)
	{
		if (grades[i] > grades[i - 1]) candies[i] = candies[i - 1] + 1;
	}

	for (int i = num-1; i > 0; i--)
	{
		if (grades[i-1] > grades[i]) candies[i-1] = candies[i] + 1;
	}

	for (int i = 0; i < num; i++)
	{
		cout << candies[i] << " ";
	}
	return 0;
}
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
