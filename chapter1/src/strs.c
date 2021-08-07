#include "strs.h"
#include <stdio.h>

/* Exercise 1-16 */
void longest_line(char s[])
{
	int i, cont, start, start_max, max;

	i = 0;
	cont = 0;
	max = 0;
	start = 0;
	start_max = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '\n' && cont > max)
		{
			max = cont;
			start_max = start;
			s[i] = '\0';
		}
		if (i > 0 && s[i - 1] == '\n')
			start = i;
		i++;
	}
	printf("%s\n", s+start);
}
void longer_than_80(char[]);
void rm_tws(char[]);
void reverse(char[]);
