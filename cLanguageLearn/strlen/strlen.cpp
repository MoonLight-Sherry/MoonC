#include "strlen.h"
#include <stdio.h>

int strlen(char *s)
{
	char *p = s;

	while (*p != '\0')
		p++;
	return p - s;
	printf("%d", p - s);
}