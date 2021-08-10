#include <new>

using namespace std;

int newtest()
{
	int* y;
	y = new int;//分配动态存储空间

	try { char(*n)[5]; }
	catch(bad_alloc)
	{
		exit(1);
	}

}