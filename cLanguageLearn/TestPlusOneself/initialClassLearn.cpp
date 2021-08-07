#include "initialClassLearn.h"
#include <iostream>
using namespace std;

class Box
{
	Box(int l);

private:
	Box * TOPointer;
	int length;

private:
	inline void set_length(int l = 1);//inline强制定义为内联函数//设置默认参数需要在参数列表结尾
	int get_length() { return length; }

};

Box MilkBox;
Box &Milk = MilkBox;

Box::Box(int l):length(l){}

void Box::set_length(int l)
{
	length = l;
}

