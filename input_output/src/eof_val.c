#include <stdio.h>
#include "input_output.h"

/* Exercise 1-6 */
/* Exercise 1-7 */
void eof_val()
{
    char c;
    while ((c = getchar()) != EOF)
    {
        printf("%c: %d is not EOF!", c, (int)c);
    }
    printf("%c: %d is EOF!", c, (int)c);
}
