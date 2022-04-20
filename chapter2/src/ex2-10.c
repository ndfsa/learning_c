#include "ch2utils.h"
#include <stdio.h>

main() {
    /* Rewrite the function lower, which converts upper case letters to lower case, with a
     * conditional expression instead of if-else.
     * */
    printf("%c\n", lower('A'));
    printf("%c\n", lower('B'));
    printf("%c\n", lower('a'));
    printf("%c\n", lower('b'));
}
