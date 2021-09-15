#include <iostream>
#include <vector>

using namespace std;


void bubble_sort(vector<int> &nums, int number)
{
	bool swapped = true;
	for (int i = 1; i < number; i++)
	{
		swapped = false;
		for (int j = 1; j < number - i + 1; j++)
		{
			if (nums[j] < nums[j - 1])
				swap(nums[j], nums[j - 1]);
			swapped = true;
		}
		if (!swapped) break;
	}
}


/*
int main()
{
	vector<int> testArray = { 1, 5, 8, 5 };
	bubble_sort(testArray, testArray.size());
	for (int i = 0; i < testArray.size(); i++)
	{
		cout << testArray[i] << endl;
	}
	return 0;
}
*/