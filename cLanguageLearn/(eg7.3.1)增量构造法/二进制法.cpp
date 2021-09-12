//此算法仅仅是输出下标，实际应用应输入另一个数组来进行存储数据
//原理：用数字的二进制位表示状态，二进制从右到左的第几个位置 表示数组元素的下标

#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>

using namespace std;

void print_subset(int n, int s) {
	//s代表的是当前二进制数表示的状态
	for (int i = 0; i < n; ++i) {
		if (s & 1 << i) {//1左移几位就代表第i个二进制位为1，其他位为0，与状态进行&运算，如果此状态包含该数字，就输出
			printf("%d ", i);
		}
	}
	printf("\n");
}

int main() {
	int n;
	while (scanf("%d", &n) == 1) {
		//一共n个数字，所以其全集有2^n个二进制1，所对应的十进制数字就是2^n - 1
		//我们要做的就是枚举出来每一种状态，1 左移 n 位，所得的十进制数字就是2^n
		for (int i = 0; i < (1 << n); ++i) {        //i表示集合元素的状态，根据该状态打印出当前集合
			print_subset(n, i);
		}
	}
	return 0;
}