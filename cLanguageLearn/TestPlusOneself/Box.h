#pragma once

class Box
{
public:
	Box(int l);
	Box() {};

private:
	Box * TOPointer;
	int length;

private:
	inline void set_length(int l = 1);//inline强制定义为内联函数//设置默认参数需要在参数列表结尾
	int get_length() { return length; }

};
