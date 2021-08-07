#include "VirtualTest.h"
#include <iostream>

using namespace std;

class base
{
public:
	virtual void display() { cout << "base" << endl; }
};

class derived: public base
{
public:
	virtual void display() { cout << "derived" << endl; }//声明同名虚函数实现多态

};

class test
{
	virtual void Test() = 0;//包含纯虚成员函数的类为抽象基类，该类无法创建对象
};

int main()
{
	base * p;
	derived test;
	p = &test;
	p->display();
	return 0;
}
