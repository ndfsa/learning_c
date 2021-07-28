#include "blanks.h"

/* Exercise 1-8 */
int count_blanks(char s[])
{
    int i = 0;
    int cont = 0;

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
    int i = 0;
    int j = 0;
    short int in_space = 0;

    while (s[i] != '\0')
    {
        if (in_space)
        {
            if (s[i] == ' ' || s[i] == '\t')
                i++;
            else
            {
                in_space = 0;
                s[j++] = s[i++];
            }
        }
        else
        {
            if (s[i] == ' ' || s[i] == '\t')
            {
                in_space = 1;
                ++i;
                s[j++] = ' ';
            }
            else
                s[j++] = s[i++];
        }
    }
	s[j] = '\0';
}

char *encode(char s[])
{
}
