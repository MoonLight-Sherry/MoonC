//此算法仅仅是输出下标，实际应用应输入另一个数组来进行存储数据
//这个比较好理解，就相当于枚举，跟二进制有点相似， 这个使用数组表示，二进制是使用数字的二进制位置表示
#include<iostream>
#include<cstring>
#include<cstdio>

using namespace std;

void print_subset_two(int n, int *B, int cur) {
	if (cur == n) {                          //已经枚举完一种状态，输出
		for (int i = 0; i < n; ++i) {
			if (B[i]) {
				printf("%d ", i);
			}
		}
		printf("\n");
		return;
	}

	B[cur] = 1;                             //该元素在下一个将要枚举的集合中
	print_subset_two(n, B, cur + 1);

	B[cur] = 0;                             //该元素不在下一个将要枚举的集合中
	print_subset_two(n, B, cur + 1);
}


int main() {
	int n, B[10];
	while (cin >> n) {
		print_subset_two(n, B, 0);
	}
	return 0;
}