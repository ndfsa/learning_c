#include <stdio.h>
#include "utils.h"

#define ASCII_LIM 128

main()
{
	int i, j, c;
	int counter[ASCII_LIM];

	for (i = 0; i < ASCII_LIM; ++i)
		counter[i] = 0;

	i = 0;
	while ((c = getchar()) != EOF)
		++counter[c];
	histogram(counter, ASCII_LIM);
}