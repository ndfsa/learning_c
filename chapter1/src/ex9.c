#include <stdio.h>
#define IS_BLANK(x) (x == ' ' || x == '\t')

main()
{
    /* Write a program to copy its input to its output, replacing each string of one or more blanks
     * by a single blank.
     * */
    int c;
    int prev;

    prev = getchar();
    printf("%c", prev);

    if (prev == EOF)
        return 0;

    while ((c = getchar()) != EOF)
    {
        if (IS_BLANK(prev) && IS_BLANK(c))
            continue;
        prev = c;
        printf("%c", c);
    }
}
