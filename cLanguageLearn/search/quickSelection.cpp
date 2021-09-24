//·ÖÖÎ

#include <iostream>
#include <vector>

using namespace std;


int quickSelection(vector<int> &nums, int left, int right)
{
	int i = left + 1, j = right;
	while (true)
	{
		while (i < right && nums[i] > nums[left]) 
			++i;
		while (j > left && nums[j] < nums[left]) 
			--j;
		if (i >= j) 
			break;
	}
	swap(nums[j], nums[left]);
	return j;
}

int findKthLargest(vector<int> &nums, int k)
{
	int left = 0, right = nums.size() - 1, target = nums.size() - k;
	while (left < right)
	{
		int mid = quickSelection(nums, left, right);

		if (mid == target)
			return nums[mid];
		if (mid < target)
			left = mid + 1;
		else
			right = mid - 1;
	}
	return nums[left];
}

/*
int main()
{
	vector<int> testArray = { 1, 5, 8, 5 };
	cout << findKthLargest(testArray, 1);
}
*/




