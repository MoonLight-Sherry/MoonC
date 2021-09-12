//此算法仅仅是输出下标，实际应用应输入另一个数组来进行存储数据
//这三种方式的话，都可以理解为输出0 - n-1的这n个数字的子集
//疑问就是我的数列并不是单纯的0 - n-1， 如果不是这种情况，那该怎么办，
//所以说，可以定义一个数据数组，这三种方式所直接输出的集合就是数据数组的下标集合
//A数组是下标数组，每次输出的是下标集合
#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

void print_subset_one(int n, int *A, int cur) {//cur是当前A数组的位置
	for (int i = 0; i < cur; ++i) {
		printf("%d ", A[i]);//如果有数据数组, 就写成data[A[i]]
	}
	printf("\n");


	int s = cur ? A[cur - 1] + 1 : 0;
	//当cur等于0的时候，这是第一次进入函数，所以选取的集合下标元素为0就可以了
	//cur不等于0的时候，即cur前面还有下标元素，为了得到全部的子集，所以这里不能漏掉，便从最小的那一个选择
	//那为什么A[cur-1]+1就是最小的下标呢，刚刚输出的最后一个下标就是A[cur-1]，所以这一个下标+1，即还未选择过的最小下标


	//从当前最小的还未选择过的下标作为下一个下标集合的首元素开始选取
	//直到n-1的下标位置，每一次选取首下标之后都开始递归
	for (int i = s; i < n; ++i) {
		A[cur] = i;
		print_subset_one(n, A, cur + 1);
	}
}

int maino() {
	int n;
	int A[10];//该数组存放的是数据数组的下标
	while (scanf_s("%d", &n) == 1) {
		print_subset_one(n, A, 0);
	}
	return 0;
}