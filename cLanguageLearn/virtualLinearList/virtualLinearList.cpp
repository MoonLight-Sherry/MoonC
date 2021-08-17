template<class T>
class linearList
{
public:
	virtual ~linearList() {};
	virtual bool empty() cost = 0;//纯虚函数用0作为初始值说明
	virtual int indexOf(cost T& theElement) {} const = 0;

};