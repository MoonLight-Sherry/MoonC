//可以直接通过sort()进行排序

#include <vector>
#include <iostream>

using namespace std;



void quick_sort(vector<int> &nums, int left, int right)
{
	if (left >= right) 
		return;

	int first = left, last = right, pivot = nums[first];

	while (first < last)
	{
		while (first < last && nums[last] >= pivot) --last;
		nums[first] = nums[last];

		while (first < last && nums[first] <= pivot) ++first;
		nums[last] = nums[first];
	}

	nums[first] = pivot;
	quick_sort(nums, left, first - 1);
	quick_sort(nums, first + 1, right);
}

/*
int main()
{
	vector<int> testArray = { 1, 5, 8, 5 };
	quick_sort(testArray, 0, testArray.size() - 1);
	for (int i = 0; i < testArray.size(); i++)
	{
		cout << testArray[i] << endl;
	}
}
*/


