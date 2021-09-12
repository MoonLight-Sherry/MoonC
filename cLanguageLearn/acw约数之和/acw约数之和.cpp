//remain to be solved；how to deal with big number?

#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;

int factorNumber = 1;

void findFactor(int n, vector<int>& v) 
{

	for (int i = 2; i <= floor(sqrt(n)); i++)
	{
		if (n % i == 0) { v.push_back(i); factorNumber++; }
	}

}

int calculateSum(vector<int> v, int b)
{
	long long s = 1;
	for (int i = 0; i < factorNumber; i++)
	{
		//cout << pow(v[i], (b + 1));
		s *= (1 - pow(v[i],(b+1))) / (1 - v[i]);
	}
	return s;
}

int main()
{
	vector <int> primeFactor;
	int A, B, C;
	long long S;
	scanf_s("%d%d", &A, &B);
	findFactor(A, primeFactor);
	//C = pow(A,B);//幂的运算
	if (factorNumber == 1) { primeFactor.push_back(A); }
	S = calculateSum(primeFactor, B);
	cout << S;
	return 0;
}