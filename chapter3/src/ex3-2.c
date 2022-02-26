#include <stdio.h>
#include "ch3utils.h"

main()
{
    /* Write a function escape(s, t) that converts characters like newline and tab into visible
     * escape sequences like \n and \t as it copies the string t to s. Use a switch. Write a
     * function for the other direction as well, converting escape sequences into the real
     * characters.
     * */

    char s[11];
    char s2[11];
    escape(s, "a\td\ns");
    rescape(s2, "a\\td\\ns");
    printf("%s\n", s);
    printf("%s\n", s2);
}
