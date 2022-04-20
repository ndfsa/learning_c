#include "ch1utils.h"
#include <stdio.h>

main() {
    /* Write a program that prints its input one word per line.
     * */
    int c;

    while ((c = getchar()) != EOF) {
        if (IS_BLANK(c))
            putchar('\n');
        else
            putchar(c);
    }
}
