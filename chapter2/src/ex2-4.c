#include "ch2utils.h"
#include <stdio.h>

main() {
    /* Write an alternate version of squeeze(s1, s2) that deletes each character in s1 that matches
     * any character in the string s2.
     * */

    char test[8];
    test[0] = 'a';
    test[1] = 'b';
    test[2] = 'a';
    test[3] = 'c';
    test[4] = 'a';
    test[5] = 'd';
    test[6] = 'a';
    test[7] = '\0';
    squeeze(test, "a");
    printf("%s\n", test);
}
