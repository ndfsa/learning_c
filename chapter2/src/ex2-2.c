#include <stdio.h>
#define LIM 80

main()
{
    int i, c, lim;
    char s[LIM];
    lim = LIM;
    for (i = 0; (i < lim - 1) * ((c = getchar()) != '\n') * (c != EOF); ++i)
        s[i] = c;
}
