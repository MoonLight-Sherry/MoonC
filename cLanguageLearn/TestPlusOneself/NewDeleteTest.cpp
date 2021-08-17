#include <iostream>
using namespace std;

void NDTest(void);

inline void NDTest(void)
{
	int * A;
	try {
		A = new int[10];
	}
	catch (bad_alloc)
	{
		cerr << "allocate failure! " << endl;
		exit (-1);
	}
	delete[] A;
}