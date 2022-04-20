#include <stdio.h>
#define LIM 10
#define DEFAULT_TS 4

void flush_spaces(int *);
main() {
    /* Write a program entab that replaces strings of blanks by the minimum number of tabs and
     * blanks to achieve the same spacing. Use the same tab stops as for detab. When either a tab
     * or a single blank would suffice to reach a tab stop, which should be given preference?
     * A. Spaces should be given preference because a new word can start right after
     * */
    int count, p, c;
    count = 0;
    p = 0;
    while ((c = getchar()) != EOF) {
        if (c == ' ') {
            p++;
            if (count > 0 && count % DEFAULT_TS == DEFAULT_TS - 1 && p > 1) {
                putchar('\t');
                p = 0;
            }
        } else {
            flush_spaces(&p);
            putchar(c);
        }

        if (c == '\n')
            count = 0;
        else
            count++;
    }
    flush_spaces(&p);
}
void flush_spaces(int *p) {
    for (; *p > 0; --(*p))
        putchar(' ');
}
