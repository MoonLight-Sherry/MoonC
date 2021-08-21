#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <map>

using namespace std;


void parse_address(const string& s, string& username, string& mta)
{
	int k = s.find('@');
	username = s.substr(0, k);
	mta = s.substr(k + 1);
}


int main()
{
	int k;
	string s, t, user1, mta1, user2, mta2;
	set<string> addr;

	while (cin >> s && s != "*")
	{
		cin >> s >> k;
		while (k--) { cin >> t; addr.insert(t + "@" + s); }
	}

	while (cin >> s && s != "*")
	{
		parse_address(s, user1, mta1);

		vector<string> mta;
		map<string, vector<string>> dest;//存放每个mta需发送的用户
		set<string> vis;
		while (cin >> t && t != "*")
		{
			parse_address(s, user2, mta2);
			if (vis.count(t)) continue;
			vis.insert(t);
			if (!dest.count(mta2)) { mta.push_back(mta2); dest[mta2] = vector<string>(); }
			dest[mta2].push_back(t);
		}


		string data;
		//输入邮件正文省略

	}

}






