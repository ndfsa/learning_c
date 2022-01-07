#include <stdio.h>
#define MAXLINE 10

main()
{
    /* Write a program to print all input lines that are longer than 80 characters.
     * */

    int c, count;
    char buffer[MAXLINE + 1];

    count = 0;
    while ((c = getchar()) != EOF)
    {
        if (c == '\n')
        {
            count = 0;
            printf("\n");
            continue;
        }
        if (count < MAXLINE)
            buffer[count] = c;
        else if (count == MAXLINE)
        {
            buffer[count] = '\0';
            printf("%s", buffer);
            putchar(c);
        }
        else
        {
            putchar(c);
        }
        ++count;
    }
    return 0;
}
