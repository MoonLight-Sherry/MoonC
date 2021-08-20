#include <string>
#include <iostream>
#include <cstdlib>
#include <list>

using namespace std;


struct studentRecord
{
	int score;
	string* name;

	int operator !=(const studentRecord& x) const
	{
		return score != x.score;
	}

	operator int() const
	{
		return score;
	}
};

ostream& operator<<(ostream& out, studentRecord& x)
{
	out << x.score << ' ' << *x.name << endl;
	return out;
}

void binSort(list<studentRecord>& theList, int range)
{
	list<studentRecord>* bin;
	bin = new list<studentRecord>[range + 1];

	int numberOfElements = theList.size();
	for (int i = 0; i <= numberOfElements; i++)
	{
		studentRecord x = theList.pop_front;
		bin[x.score].push_back(x);
	}
}

