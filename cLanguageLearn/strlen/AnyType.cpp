#include <iostream>
#include <array>
using namespace std;

template<class T, int S>
class array
{
public:
	array();
	T & operator[](int);

private:
	int length;
	T * num;
};

template<class T, int S>
T & array<T, S>::operator[] (int i)
{
	if (i < 0 || i >= length)
		throw string("out of bounds");
	return num[i];
}