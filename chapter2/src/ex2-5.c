#include <stdio.h>
#include "ch2utils.h"

main()
{
    /* Write the function any(s1, s2), which returns the first location in the string s1 where any
     * character from the string s2 occurs, or -1 if s1 contains s2. (The standard library function
     * strpbrk does the same job but returns a pointer to the location.)
     * */

    printf("%d\n", any("asdfgqwert", "p"));
}
