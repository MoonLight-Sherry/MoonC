#include<iostream>
#include<unordered_map>
using namespace std;
typedef long long LL;

const int mod = 9901;
int A, B;

//�����������Լ����ֵĴ���
unordered_map<int, int> primes;

//�Գ��������ӷֽ�
void divide(int n) {
	for (int i = 2; i <= n / i; i++) {
		if (n % i == 0) {
			while (n % i == 0) {
				primes[i]++;
				n /= i;
			}
		}
	}
	if (n > 1) {
		primes[n]++;
	}
}

//������
int qmid(int a, int b) {
	int res = 1;
	while (b) {
		if (b & 1) res = (LL)res * a % mod;
		a = (LL)a * a % mod;
		b >>= 1;//����һλ����ֵ����2
	}
	return res;
}

//p0 + .. + pk-1
int sum(int p, int k) {
	if (k == 1) return 1;  //�߽�
	if (k % 2 == 0) {
		return (LL)(qmid(p, k / 2) + 1) * sum(p, k / 2) % mod;//���������ȡģ��ʹ�ò����
	}
	return (qmid(p, k - 1) + sum(p, k - 1)) % mod;
}

int main() {
	cin >> A >> B;

	//��A�ֽ�������
	divide(A);

	int res = 1;
	for (auto it : primes) {
		//p�������ӣ�k�������ӵĴ���
		int p = it.first, k = it.second * B;
		// resҪ����ÿһ��, ע��������k + 1
		res = (LL)res * sum(p, k + 1) % mod;
	}
	if (!A) res = 0;

	cout << res << endl;

	return 0;
}
