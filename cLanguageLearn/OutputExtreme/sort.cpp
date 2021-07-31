#include "sort.h"

void sort(int *pa, int *left, int *right)
{
	int *i, *last;

	if (left >= right)
			return;

	last = left;
	for (i = left+1 ; i <= right; i++)
		if ((*i) < (*left))
			swap(&pa[(*++last)], &pa[(*i)]);
	swap(&pa[(*left)], &pa[*last]);
	sort(pa,left, last - 1);
	sort(pa, last + 1, right);
}