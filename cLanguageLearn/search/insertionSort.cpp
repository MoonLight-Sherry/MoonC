#include <vector>
#include <iostream>

using namespace std;

void insertion_sort(vector<int> &nums, int number)
{
	for (int i = 0; i < number; ++i)
	{
		for (int j = i; j > 0 && nums[j] < nums[j - 1]; --j)
		{
			swap(nums[j], nums[j - 1]);
		}
	}
}


/*
int main()
{
	vector<int> testArray = { 1, 5, 8, 5 };
	insertion_sort(testArray, testArray.size());
	for (int i = 0; i < testArray.size(); i++)
	{
		cout << testArray[i] << endl;
	}
}
*/





