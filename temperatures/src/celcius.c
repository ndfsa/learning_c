#include <stdio.h>

main()
{
    float fahr, celcius;
    int lower, upper, step;

    lower = 0;
    upper = 300;
    step = 20;

    celcius = lower;
    /* print header table */
    printf("celcius | fahrenheit\n--------------------\n");

    while (celcius <= upper)
    {
        fahr = 1.8 * celcius + 32.0;
        printf("%7.3f | %10.3f\n", celcius, fahr);
        celcius = celcius + step;
    }
}
