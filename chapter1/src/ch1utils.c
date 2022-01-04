#include "ch1utils.h"
#include <stdio.h>

#define WIDTH 50.0
#define HEIGHT 30

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

	printf("vertical axis scale: %d\n", max);
	for (i = 0; i < HEIGHT; ++i)
	{
		if (i == 0)
			printf("1.0 ┎ ");
		else if (i == HEIGHT / 2)
			printf("0.5 ┠ ");
		else if (i == HEIGHT - 1)
			printf("0.0 ┠ ");
		else
			printf("    ┃ ");

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
	printf("    ┗");
	for (j = 0; j < lim; ++j)
		if (counter[j] > 0)
			printf("━┷");
	printf("\n");
	for (i = 0; i < 3; ++i)
	{
		printf("      ");
		for (j = 0; j < lim; ++j)
			if (counter[j] > 0)
				printf("%1d ", j % (factor * 10) / factor);
		printf("\n");
		factor = factor / 10;
	}
}

int getline(char s[], int lim)
{
	int c, i;

	i = 0;
	while ((c = getchar()) != EOF && c != '\n')
	{
		if (i < lim - 1)
			s[i] = c;
		++i;
	}

	s[i < lim - 1 ? i : lim - 1] = '\0';
	return i;
}

void copy(char from[], char to[])
{
	int i;

	i = 0;
	while ((to[i] = from[i]) != '\0')
		++i;
}
