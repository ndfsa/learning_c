#include <stdio.h>

#define ASCII_LIM 128
#define HEIGHT 30

main()
{
    int counter[ASCII_LIM];
    int max;

    int ntab, nspaces, nl, c, i, j;

    for (i = 0; i < ASCII_LIM; ++i)
        counter[i] = 0;

    while ((c = getchar()) != EOF && c < 128)
        ++counter[c];

    max = -1;
    for (i = 0; i < ASCII_LIM; ++i)
        if (counter[i] > max)
            max = counter[i];

    for (i = 0; i < HEIGHT; ++i)
    {
        int j;
        for (j = 0; j < ASCII_LIM; ++j)
            if (counter[j] > 0)
            {
                if (i * max >= HEIGHT * (max - counter[j]))
                    printf("- ");
                else
                    printf("  ");
            }
        printf("\n");
    }

    int factor;
    factor = 100;
    for (i = 0; i < 3; ++i)
    {
        for (j = 0; j < ASCII_LIM; ++j)
            if (counter[j] > 0)
                printf("%1d ", j % (factor * 10) / factor);
        printf("\n");
        factor = factor / 10;
    }
    return 0;
}
