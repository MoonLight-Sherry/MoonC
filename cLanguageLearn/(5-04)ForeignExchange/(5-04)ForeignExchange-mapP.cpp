#include <iostream>
#include <map>

using namespace std;

map<int, int>studentPair;

int main()
{
	int studentSum = 0;
	while (cin >> studentSum && studentSum != 0)
	{
		int n2 = 0; int n1 = 0; studentPair.clear();
		for (int i = studentSum; i > 0; i--)
		{
			int student1, student2 = 0;
			cin >> student1 >> student2;
			if (studentPair[student1] == student2 && studentPair[student2] == student1) n1++;//记录过
			else n2++;//未记录过
			studentPair[student1] = student2;
			studentPair[student2] = student1;
		}
		if (n2 % 2 == 0 && n1 % 2 == 0 && n1 != 0 && n2 != 0) cout << "YES" << endl;
		else cout << "NO" << endl;
	}

}















