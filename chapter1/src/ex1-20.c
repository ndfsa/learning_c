#include <stdio.h>
#define DEFAULT_TS 4
#define IN 1
#define OUT 0

main() {
    /* Write a program detab that replaces tabs in the input with the propper number of blanks to
     * space to the next tabs stop. Assume a fixed set of tab stop, say every n columns. Should n
     * be a variable or a symbolic parameter?
     * A. I think it should be a symbolic parameter, as the book does not mention command line
     * arguments, in which case a variable with a symbolic parameter fallback would be preferable.
     * */
    int count, offset;
    int c;

    while ((c = getchar()) != EOF) {
        if (c == '\t') {
            offset = DEFAULT_TS - (count % 4);
            printf("%*s", offset, "");
            count += offset;
        } else
            putchar(c);

        if (c == '\n')
            count = 0;
        else
            count++;
    }
}
