//归并排序
//分治法
//右值不包含

#include <iostream>
#include <vector>

using namespace std;

void merge_sort(vector<int> &nums, int left, int right, vector<int> &temp)
{
	//divide
	if (left + 1 >= right) return;

	int mid = left + (right - 1) / 2;
	merge_sort(nums, left, mid, temp);
	merge_sort(nums, mid, right, temp);

	//conquer
	int p = left, q = mid, cur = left;
	while (p < mid || q < right)
	{
		if (q >= right || (p < mid && nums[p] <= nums[q]))
			temp[cur++] = nums[p++];
		else
			temp[cur++] = nums[q++];
	}
	for (int i = left; i < right; ++i)
		//cout << temp[i] << " replaced " << nums[i] << "; ";
		nums[i] = temp[i];
}


/*
int main()
{
	vector<int> testArray = { 1, 5, 8, 5 };
	vector<int> temp = { 0, 0, 0, 0 };
	merge_sort(testArray, 0, testArray.size(), temp);
	for (int i = 0; i < testArray.size(); i++)
	{
		cout << testArray[i] << endl;
	}
}
*/


