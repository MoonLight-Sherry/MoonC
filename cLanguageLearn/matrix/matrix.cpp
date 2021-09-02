#include<iostream>

using namespace std;

template<class T>

class matrix
{
	friend ostream& operator << (ostream&, const matrix<T>&) {};

public:
	matrix(int theRows = 0, int theColumns = 0) {};
	matrix(const matrix<T>&) {};
	~matrix() { delete[] element; }

	int rows() const { return theRows; }
	int columns() cosnt { return theColumns; }
	T& operator()(int i, int j) const {};
	matrix<T>& operator= (const matrix<T>&) {};


private:
	int theRows;
	int theColumns;
	T* element;

};














