//���㷨����������±꣬ʵ��Ӧ��Ӧ������һ�����������д洢����
//����ȽϺ���⣬���൱��ö�٣����������е����ƣ� ���ʹ�������ʾ����������ʹ�����ֵĶ�����λ�ñ�ʾ
#include<iostream>
#include<cstring>
#include<cstdio>

using namespace std;

void print_subset_two(int n, int *B, int cur) {
	if (cur == n) {                          //�Ѿ�ö����һ��״̬�����
		for (int i = 0; i < n; ++i) {
			if (B[i]) {
				printf("%d ", i);
			}
		}
		printf("\n");
		return;
	}

	B[cur] = 1;                             //��Ԫ������һ����Ҫö�ٵļ�����
	print_subset_two(n, B, cur + 1);

	B[cur] = 0;                             //��Ԫ�ز�����һ����Ҫö�ٵļ�����
	print_subset_two(n, B, cur + 1);
}


int main() {
	int n, B[10];
	while (cin >> n) {
		print_subset_two(n, B, 0);
	}
	return 0;
}