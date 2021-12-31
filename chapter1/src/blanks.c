#include "blanks.h"
/*
 *	Exercise 1-11
 *	The inputs I would send would be:
 *	1) an empty word
 *	2) sequences of \n \t and ' '
 *	3) a gigantic input, surely someting big enough will overflow something
 *	4) 4 byte characters? 6 byte? something weird
 *	5) null characters? would it count as a word?
 * */

/* Exercise 1-12 */
/* this function still has leading and trailing whitespaces */
void word_per_line(char s[])
{
	int i;
	fold_blanks(s);

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == ' ')
			s[i] = '\n';
		i++;
	}
}
