#include <string>
#include <iostream>

int main()
{
	string s;
	string s1(10, 's');//10个s
	char c1 = s1.c_str();//c_str把string转化为字符串指针
	s1.erase(5, 3);//erase删除下标5开始的三个元素、

}