#include "ch3utils.h"
#include <stdio.h>

main() {
    /* Write a function expand(s1, s2) that expands shorthand notations like a-z in the string s1
     * into the equivalent complete list abc...xyz in s2. Allow for letters of either case and
     * digits , and be prepared to handle cases like a-b-c and a-z0-9 and -a-z. Arrange that a
     * leading or trailing - is taken literally.
     * */

    char res[100];
    expand("a-r-z", res);
    printf("%s\n", res);
    expand("a-z0-9", res);
    printf("%s\n", res);
    expand("-a-z", res);
    printf("%s\n", res);
    expand("a-z-", res);
    printf("%s\n", res);
    return 0;
}
