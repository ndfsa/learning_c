#include <stdio.h>

#define ASCII_LIM 128
#define WIDTH 50.0

main()
{
    int counter[ASCII_LIM];
    int max;

    int ntab, nspaces, nl, c, i;

    for (i = 0; i < ASCII_LIM; ++i)
    {
        counter[i] = 0;
    }

    while ((c = getchar()) != EOF && c < 128)
    {
        ++counter[c];
    }

    max = -1;
    for (i = 0; i < ASCII_LIM; ++i)
        if (counter[i] > max)
            max = counter[i];

    for (i = 0; i < ASCII_LIM; ++i)
    {
        if (counter[i] > 0)
        {
            printf("%3d: %5d\t", i, counter[i]);
            int j;
            for (j = 0; j * max < WIDTH * counter[i]; ++j)
                putchar('|');
            printf("\n");
        }
    }

    return 0;
}
