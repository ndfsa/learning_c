#include "histogram.h"
#include <stdio.h>

#define ASCII_LIM 128
#define WIDTH 50.0
#define HEIGHT 30

/* Exercise 1-14 */
void c_histogram(char s[])
{
	int counter[ASCII_LIM];
	int max;

	int ntab, nspaces, nl, i;
	int j;

	for (i = 0; i < ASCII_LIM; ++i)
		counter[i] = 0;

	i=0;
	while (s[i] != '\0')
		++counter[s[i++]];

	max = -1;
	for (i = 0; i < ASCII_LIM; ++i)
		if (counter[i] > max)
			max = counter[i];

	for (i = 0; i < ASCII_LIM; ++i)
		if (counter[i] > 0)
		{
			printf("%3d: %5d\t", i, counter[i]);
			for (j = 0; j * max < WIDTH * counter[i]; ++j)
				putchar('|');
			printf("\n");
		}
}

void c_vhistogram(char s[])
{
	int counter[ASCII_LIM];
	int max;
	int ntab, nspaces, nl, i, j;
	int factor;

	for (i = 0; i < ASCII_LIM; ++i)
		counter[i] = 0;

	i=0;
	while (s[i] != '\0')
		++counter[s[i++]];

	max = -1;
	for (i = 0; i < ASCII_LIM; ++i)
		if (counter[i] > max)
			max = counter[i];

	for (i = 0; i < HEIGHT; ++i)
	{
		for (j = 0; j < ASCII_LIM; ++j)
			if (counter[j] > 0)
			{
				if (i * max >= HEIGHT * (max - counter[j]))
					printf("- ");
				else
					printf("  ");
			}
		printf("\n");
	}

	factor = 100;
	for (i = 0; i < 3; ++i)
	{
		for (j = 0; j < ASCII_LIM; ++j)
			if (counter[j] > 0)
				printf("%1d ", j % (factor * 10) / factor);
		printf("\n");
		factor = factor / 10;
	}
}
