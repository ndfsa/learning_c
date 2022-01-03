#include <stdio.h>
#include <string.h>

/* Exercise 1-17 */
void longer_than(char s[], int thresh)
{
	int i, cont, start, len;

	cont = start = 0;
	len = strlen(s);
	for (i = 0; i < len; i++)
	{
		if (s[i] == '\n' || s[i] == '\0')
		{
			if (cont >= thresh)
			{
				s[i] = '\0';
				printf("%s\n", s + start);
			}
			cont = 0;
			start = i + 1;
		}
		else
			cont++;
	}
}

void rm_tws(char[]);
void reverse(char[]);
