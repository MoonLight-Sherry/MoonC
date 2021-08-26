#include <iostream>
#include <set>
#include <cstring>
#include <sstream>
#include <algorithm>

using namespace std;

int a[3];
string s;
set<string>ss;

int main()
{
	int n = 0;

	while (cin >> n && n != 0)
	{
		int n1, n2 = 0;
		for (int i = n; i > 0; i--)
		{
			cin >> a[0] >> a[1];
			stringstream pp;
			for (int j = 0; j <= 1; j++)
			{
				pp << a[j];
				s = pp.str();
			}

			sort(s.begin(), s.end());
			if (find(ss.begin(), ss.end(), s) == ss.end()) { n1++; }
			else { ss.insert(s); n2++; }
		}
		if (n2 % 2 == 0 && n1 % 2 == 0 && n1 != 0 && n2 != 0) cout << "YES" << endl;
		else cout << "NO" << endl;
	}

}