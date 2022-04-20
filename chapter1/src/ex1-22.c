#include "ch1utils.h"
#include <stdio.h>
#define MAX_LENGTH 100

main() {
    /* Write a program to "fold" long input lines into two or more shorter lines after the last
     * non-blank character that occurs before the n-th column of input. Make sure your program does
     * something intelligent with very long lines, and if there are no blanks or tabs before the
     * specified column.
     * */

    int c, count, last_blank, offset;
    char buffer[MAX_LENGTH + 1];
    offset = 0;
    count = 0;
    clear_buffer(buffer, MAX_LENGTH + 1);
    last_blank = -1;

    while ((c = getchar()) != EOF) {
        if (count + offset < MAX_LENGTH) {
            if (IS_BLANK(c))
                last_blank = count;

            buffer[count++] = c;
            continue;
        }

        if (last_blank != -1) {
            buffer[last_blank] = '\n';
            offset = MAX_LENGTH - last_blank - 2;
            printf("%s", buffer);
            clear_buffer(buffer, MAX_LENGTH);

            count = 0;
            buffer[count++] = c;
            continue;
        }
        count = 0;
        offset = 0;
        printf("%s", buffer);
        clear_buffer(buffer, MAX_LENGTH);

        while (1) {
            if (IS_BLANK(c)) {
                putchar('\n');
                break;
            } else if (c == EOF) {
                return 0;
            } else {
                putchar(c);
            }
            c = getchar();
        }
    }
    printf("%s", buffer);
}
