#include <set>
#include <map>
#include <vector>
#include <stack>
#include <iterator>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

typedef set<int> IdSetType;
map<IdSetType, int> IDcache;//给不同集合映射唯一的ID
vector<IdSetType> Setcache;//集合的（集合）,根据ID取集合

int ID(IdSetType x)//查找给定的集合，若无，则新建
{
	if (IDcache.count(x)) return IDcache[x];
	Setcache.push_back(x);//添加新集合
	return IDcache[x] = Setcache.size() - 1;
}

#define ALL(x) x.begin(),x.end()
#define INS(x) inserter(x,x.begin())

using namespace std;

int main()
{
	stack<int> s;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string op;
		cin >> op;
		if (op[0] == 'P') s.push(ID(IdSetType()));
		else if (op[0] == 'D') s.push(s.top());
		else {
			IdSetType x1 = Setcache[s.top()]; s.pop();
			IdSetType x2 = Setcache[s.top()]; s.pop();
			IdSetType x;
			if (op[0] == 'U') set_union (ALL(x1), ALL(x2), INS(x));
			if (op[0] == 'I') set_intersection (ALL(x1), ALL(x2), INS(x));
			s.push(ID(x));
		}
		cout << Setcache[s.top()].size() << endl;
	}




}



