//UVa1593 - Alignment of Code
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<sstream>
#include<iterator>
#include<iomanip>
using namespace std;

vector<string> text[1009];
int num[100] = { 0 }, X = 0;
char line[200];

int main()
{
	//freopen("in.txt", "r", stdin);
	while (cin.getline(line, 200)) {
		istringstream in(line);
		istream_iterator<string> fi(in), eof;
		int y = 0;
		while (fi != eof) {
			text[X].push_back(*fi);
			num[y] = max(num[y], (int)fi->size());
			++y, ++fi;
		}
		++X;
	}
	for (int i = 0; i < X; ++i) {
		int t = text[i].size() - 1;
		for (int j = 0; j < t; ++j)
			cout << left << setw(num[j] + 1) << text[i][j];
		cout << *(text[i].rbegin()) << '\n';
	}
	return 0;
}