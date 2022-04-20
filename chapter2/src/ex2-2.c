#include <stdio.h>
#define LIM 80

main() {
    int i, c, lim;
    char s[LIM];
    lim = LIM;
    for (i = 0, c = getchar(); (i < lim - 1) * (c != '\n') * (c != EOF); ++i, c = getchar())
        s[i] = c;
}
