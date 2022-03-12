#include <stdio.h>
#include "ch3utils.h"

main()
{
    /* Write a version of itoa that accepts three arguments instead of two. The third argument is a
     * minimum field width; the converted number must be padded with blanks on the left if
     * necessary to make it wide enough.
     * */

    char buffer[100];
    itoa_w(1010101010, buffer, 10);
    printf("%s\n", buffer);
}
