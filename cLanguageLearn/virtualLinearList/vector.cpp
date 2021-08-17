
template <typename Object>//Object是int string之类的类型
class Vector
{
public:
	explicit Vector(int initSize = 0)//explicit用来标识这个函数只能显示调用，不能隐式调用，防止出错。
		:theSize(initSize), theCapacity(initSize + SPARE_CAPACITY)//构造函数的初始化列表，以一个冒号开始，之后是以逗号分隔的数据成员列表   这里把容量（capacity）初始化的比大小（size）稍微大一点，留了一个余量
	{
		objects = new Object[theCapacity];
	}

	Vector(const Vector & rhs) :objects(NULL)//拷贝构造函数，这里先让objects指向NULL，防止浅拷贝
	{
		operator=(rhs);
	}

	~Vector()
	{
		delete[] objects;
	}

	const Vector & operator= (const Vector & rhs)
	{
		if (this != rhs)//混淆检测
		{
			delete[] objects;
			theSize = rhs.size();
			theCapacity = rhs.theCapacity;
			object = new Object[capacity()];
			for (int k = 0; k < size(); k++)
				object[k] = rhs.objects[k];
		}
		return *this;
	}

	void resize(int newSize)
	{
		if (newSize > theCapacity)
			reserve(newSize * 2 + 1);
		theSize = newSize;
	}

	void reserve(int newCapacity)//改变vector预先给它分配的内存大小
	{
		if (newCapacity < theSize)
			return;

		Object *oldArray = objects;//oldArray指向老空间
		objects = new Object[newCapacity];//给objects分配新空间
		for (int k = 0; k < theSize; k++)
			objects[k] = oldArray[k];
		theCapacity = newCapacity;
		delete[] oldArray;
	}

	//以上为主要模块，以下为一些其他的功能
	Object & operator[] (int index)//返回引用，使得这个元素是可以改的
	{
		return objects[index];
	}
	const Object & operator[](int index) const//这种是不可以改的,只能观测
	{
		return objects[index];
	}

	bool empty() const
	{
		return size() == 0;
	}

	int size() const
	{
		return theSize;
	}

	int capacity() const
	{
		return theCapacity;
	}

	void push_back(const Object &x)//数组后添加一个元素
	{
		if (theSize == theCapacity)
		{
			reserve(2 * theCapacity + 1);
		}
		objects[theSize++] = x;
	}

	void pop_back()//数组后减少一个元素
	{
		theSize--;
	}

	const Object & back() const
	{
		return objects[theSize - 1];
	}

	//迭代器的定义
	typedef Object * iterator;
	typedef const Object * const_iterator;//两种迭代器，一个指向的值可以改，一个不可以改

	iterator begin()
	{
		return &objects[0];
	}

	const_iterator begin() const
	{
		return &objects[0];
	}

	iterator end()
	{
		return &objects[size()];
	}

	const_iterator end() const
	{
		return &objects[size()];
	}

	enum { SPACE_CAPACITY = 16 };//枚举类型，如果字符串很长，并且没几个，可以用这种办法



private:
	int theSize;                   //vector现在存了几个容量
	int theCapacity;               //vector能存几个元素
	Object* objects;               //vector的每个元素。
};