#include <stdio.h>

main () {
    int nl;
    int c;

    nl = 0;
    while ((c = getchar()) != EOF)
        if (c == '\n')
            ++nl;
    printf("%3d", nl);
}
