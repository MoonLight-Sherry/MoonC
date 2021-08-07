#include "Book.h"


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
		return 0;
	}