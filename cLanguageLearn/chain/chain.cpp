#include "chainNode.cpp"

using namespace std;

template<class T>
class chain
{
public:
	chain(int initialCapocity = 10);
	chain(const chain<T>& theList);
	~const();


protected:
	chainNode<T>* firstNode;
	int listSize;
};


template<class T>
chain<T>::chain(int initialCapacity)
{

}


template<class T>
chain<T>::chain(const chain<T>& theList)
{

}

