#include "ch1utils.h"
#include <stdio.h>
#define LIM 100

int trim_buffer(char *, int);
main()
{
    /* Write a program to remove trailing blanks and tabs from each line of input and to delete
     * entirely blank lines.
     * */
    int p, c;
    char buffer[LIM + 1];

    p = 0;
    c = 0;

    while ((c = getchar()) != EOF)
    {
        if (p < LIM)
        {
            buffer[p++] = c;
            if (c == '\n' && trim_buffer(buffer, p))
            {
                printf("%s", buffer);
            }
        }
    }
}

int trim_buffer(char *buffer, int p)
{
    /* TODO: trim buffer and set null character */
    return !(buffer[0] == '\n');
}
