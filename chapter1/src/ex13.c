#include "ch1utils.h"
#include <stdio.h>

#define IS_BLANK(x) (x == ' ' || x == '\t')
#define LIMIT 45
#define OUT 0
#define IN 1

main()
{
    /* Write a program to print a histogram of the lengths of words in its input. It is easy to
     * draw the histogram with the bars horizontal; a vertical orientation is more challenging.
     * */
    int state, i, letters, c;
    int counter[LIMIT];

    state = OUT;
    letters = 0;
    i = 0;

    for (i = 0; i < LIMIT; ++i)
        counter[i] = 0;

    while ((c = getchar()) != EOF)
    {
        if (IS_BLANK(c) || c == '\n')
        {
            state = OUT;
            if (letters > 0)
                ++counter[(letters >= LIMIT ? LIMIT - 1 : letters)];
            letters = 0;
        }
        else if (state == OUT)
        {
            state = IN;
            letters++;
        }
        else if (state == IN)
            letters++;
        ++i;
    }
    /* vhistogram(counter, LIMIT); */
    histogram(counter, LIMIT);
}
