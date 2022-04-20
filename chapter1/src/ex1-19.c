#include "ch1utils.h"
#include <stdio.h>

#define LIM 100

main() {
    /* Write a function reverse(s) that reverses the character string s. Use it to write a program
     * that reverses its input a line at a time.
     * */
    char buffer[LIM];
    int p;
    int c;

    clear_buffer(buffer, LIM);
    p = 0;

    while ((c = getchar()) != EOF) {
        if (p < LIM - 1 && c == '\n') {
            reverse(buffer);
            printf("%s\n", buffer);
            p = 0;
            clear_buffer(buffer, LIM);
        } else if (c == '\n') {
            printf("Buffer size exceeded: %d\n", p);
            p = 0;
            clear_buffer(buffer, LIM);
        } else if (p < LIM - 1)
            buffer[p++] = c;
    }
}
