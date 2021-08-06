#include "histogram.h"
#include <stdio.h>

#define ASCII_LIM 128
#define WORD_LIM 50
#define WIDTH 50.0
#define HEIGHT 30
#define OUT 0
#define IN 1

/* Exercise 1-13 */
void word_length_count(char s[], int counter[], int limit)
{
	int state, i, letters;

	letters = 0;
	state = OUT;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		{
			state = OUT;
			if (letters > 0)
				++counter[(letters >= limit ? limit - 1 : letters)];
			letters = 0;
		}
		else if (state == OUT)
		{
			state = IN;
			letters++;
		}
		else if (state == IN)
			letters++;
		++i;
	}
	if (letters > 0)
		++counter[(letters >= limit ? limit - 1 : letters)];
}

/* Exercise 1-14 */
void frequency_count(char s[], int counter[])
{
	int i, j;

	for (i = 0; i < ASCII_LIM; ++i)
		counter[i] = 0;

	i = 0;
	while (s[i] != '\0')
		++counter[s[i++]];
}

int counter_max(int counter[], int lim)
{
	int i, max;

	max = -1;
	for (i = 0; i < lim; ++i)
		if (counter[i] > max)
			max = counter[i];
	return max;
}

void histogram(int counter[], int lim)
{
	int i, j, max;

	max = counter_max(counter, lim);
	for (i = 0; i < lim; ++i)
		if (counter[i] > 0)
		{
			printf("%3d: %5d\t", i, counter[i]);
			for (j = 0; j * max < WIDTH * counter[i]; ++j)
				printf("█");
			printf("\n");
		}
}

void vhistogram(int counter[], int lim)
{
	int i, j, max;
	int factor;

	max = counter_max(counter, lim);
	for (i = 0; i < HEIGHT; ++i)
	{
		for (j = 0; j < lim; ++j)
			if (counter[j] > 0)
			{
				if (i * max >= HEIGHT * (max - counter[j]))
					printf("█ ");
				else
					printf("  ");
			}
		printf("\n");
	}

	factor = 100;
	for (i = 0; i < 3; ++i)
	{
		for (j = 0; j < lim; ++j)
			if (counter[j] > 0)
				printf("%1d ", j % (factor * 10) / factor);
		printf("\n");
		factor = factor / 10;
	}
}
