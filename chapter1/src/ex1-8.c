#include <stdio.h>

main()
{
    /* Write a program to count blanks, tabs and newlines.
     * */
    int c;
    int space, tab, nl;

    space = 0;
    tab = 0;
    nl = 0;

    while ((c = getchar()) != EOF)
    {
        if (c == ' ')
            space++;
        if (c == '\t')
            tab++;
        if (c == '\n')
            nl++;
    }
    printf("spaces: %d\ntabs: %d\nnl: %d\n", space, tab, nl);
}
