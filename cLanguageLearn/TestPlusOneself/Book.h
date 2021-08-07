#pragma once

class BookTest
{
public:
	explicit BookTest(char a);//explicit限制类型转换
	void setTitle(char a) { Title = a; }
	void serPrice(int price) { this->price = price; }
	int getPrice() const { return price; }
	BookTest(BookTest &b);//默认只拷贝指针
	char Title;
	int price;
	~BookTest() {};//析构函数
private:
	BookTest() {};
	static int count;
};

