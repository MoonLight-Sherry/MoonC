#include <iostream>
#include <vector>

using namespace std;


int binarySearch1(vector<int>& nums, int target)
{
	int left = 0, right = nums.size() - 1, mid;
	while (left < right)
	{
		mid = (left + right) / 2;
		if (nums[mid] == target) return mid;
		else if (nums[mid] < target) left = mid + 1;
		else right= mid - 1;
	}
	return -1;
}

int main()
{
	vector<int> testArray = { 1, 2, 3, 5 };
	cout << binarySearch1(testArray, 3) << endl;
}




