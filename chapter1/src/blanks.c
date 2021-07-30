#include "blanks.h"
#define IS_BLANK(x) (x == ' ' || x == '\t')

/* Exercise 1-8 */
int count_blanks(char s[])
{
	int i;
	int cont;

	i = 0;
	cont = 0;

	while (s[i] != '\0')
	{
		if (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
			cont++;
		i++;
	}
	return cont;
}

/* Exercise 1-9 */
void fold_blanks(char s[])
{
	int i;
	int j;

	i = j = 0;

	while (s[i] != '\0')
	{
		/* Need to check for tabs and convert them to spaces */
		s[j++] = s[i++] == '\t' ? ' ' : s[i - 1];
		if (IS_BLANK(s[i]) && IS_BLANK(s[j - 1]))
			j--;
	}
	s[j] = '\0';
}

/* Exercise 1-10 */
void encode(char s[], char res[])
{
	int i;
	int j;

	i = 0;
	j = 0;

	while (s[i] != '\0')
	{
		switch (s[i])
		{
		case '\\':
			res[j++] = '\\';
			res[j++] = '\\';
			i++;
			break;
		case '\t':
			res[j++] = '\\';
			res[j++] = 't';
			i++;
			break;
		case '\b':
			res[j++] = '\\';
			res[j++] = 'b';
			i++;
			break;
		default:
			res[j++] = s[i++];
			break;
		}
	}
	res[j] = '\0';
}
