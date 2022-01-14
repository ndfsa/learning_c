#include "ch1utils.h"
#include <stdio.h>
#define IN 1
#define OUT 0
#define LIM 100

void clear_buffer(char *);
void flush_buffer(char *);
int is_empty(char *);

main()
{
    /* Write a program to remove trailing blanks and tabs from each line of input and to delete
     * entirely blank lines.
     * */
    int p, c;
    short int state;
    char buffer[LIM + 1];

    p = 0;
    c = 0;

    state = IN;
    clear_buffer(buffer);

    while ((c = getchar()) != EOF)
    {
        if (state == OUT && IS_BLANK(c))
        {
            if (p >= LIM)
            {
                flush_buffer(buffer);
                p = 0;
            }
            buffer[p++] = c;
        }
        else if (state == OUT)
        {
            if (c == '\n' && !is_empty(buffer))
                clear_buffer(buffer);
            else
                flush_buffer(buffer);

            p = 0;
            state = IN;
            putchar(c);
        }
        else if (IS_BLANK(c))
        {
            buffer[p++] = c;
            state = OUT;
        }
        else
        {
            putchar(c);
        }
    }
}

void clear_buffer(char *buffer)
{
    int i;
    for (i = 0; i <= LIM; ++i)
    {
        buffer[i] = '\0';
    }
}

void flush_buffer(char *buffer)
{
    printf("%s", buffer);
    clear_buffer(buffer);
}

int is_empty(char *buffer)
{
    int i;
    for (i = 0; i < LIM; ++i)
        if (buffer[i] != '\0')
            return 0;
    return 1;
}
