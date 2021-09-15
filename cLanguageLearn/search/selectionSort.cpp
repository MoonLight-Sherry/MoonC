#include <iostream>
#include <vector>

using namespace std;

void selection_sort(vector<int> &nums, int numbers)
{
	int curMin;
	for (int i = 0; i < numbers - 1; i++)
	{
		curMin = i;
		for (int j = 1; j < numbers; j++)
		{
			if (nums[j] < nums[i])
				curMin = j;
		}
		swap(nums[i], nums[curMin]);
	}
}


int main()
{
	vector<int> testArray = { 1, 5, 8, 5 };
	selection_sort(testArray, testArray.size());
	for (int i = 0; i < testArray.size(); i++)
	{
		cout << testArray[i] << endl;
	}
	return 0;
}