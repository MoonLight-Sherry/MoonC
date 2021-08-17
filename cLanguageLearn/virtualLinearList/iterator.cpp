//双向迭代器

template<class T>
class iterator
{
public:
	typedef bidirectional_iterator_tag iterator_category;//标签定义分类
	typedef T value_type;
	typedef ptrdidd_t difference_type;
	typedef T* pointer;
	typedef T& reference;

	iterator(T* thePosition = 0) { position = thePosition; }

	T& operator*() { return *position; }
	T* operator->() { return &*position; }

	iterator& operator++()//前加
	{
		++position; return *this;
	}
	iterator& operator++(int)//后加
	{
		iterator old = *this;
		++position;
		return old;
	}


private:
	T* position;


};