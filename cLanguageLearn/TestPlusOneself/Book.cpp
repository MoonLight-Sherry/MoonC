#include "Book.h"

class BookTest
{
public :
	explicit BookTest(char a);//explicit限制类型转换
	void setTitle(char a) { Title = a; }
	void serPrice(int price) { this->price = price; }
	int getPrice() const { return price; }
	BookTest(BookTest &b);//默认只拷贝指针
	char Title;
	int price;
	~ BookTest();//析构函数
private:
	BookTest() {};
	static int count;
};

int BookTest::count = 0;//static定义必须在函数外

	BookTest::BookTest(char a)
{
	Title = a;
}


	class codingBook : public BookTest//继承
	{
	private:
		using BookTest::Title;//using更改属性
	};

	int mainp()
	{
		const BookTest Alice('I');
		const char * Test = "test";
	}