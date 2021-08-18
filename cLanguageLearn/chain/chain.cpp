#include "chainNode.cpp"

using namespace std;

template<class T>
class chain
{
public:
	chain(int initialCapocity = 10);
	chain(cosnt chain<T> &);
	~const();


protected:
	chainNode<T>* firstNode;
	int listSize;
};


template<class T>
chain<T> ::chain(const chain<T>& theList)
{

}

