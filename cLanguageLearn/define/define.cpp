#include <stdio.h>

#define Book(n) "c"#n

int main()
{
	char c = 'b';
	printf("%s", Book(book));
	printf("%c", c);
	return 0;
}



