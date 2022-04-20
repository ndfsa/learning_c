#include <stdio.h>

main() {
    /* Write a program to print the corresponding Celsius to Fahrenheit table.
     * */

    float celsius, fahr;
    int lower, upper, step;

    printf("celcius | fahrenheit\n--------------------\n");

    lower = 0;
    upper = 300;
    step = 20;

    celsius = lower;

    while (celsius <= upper) {
        fahr = 1.8 * celsius + 32.0;
        printf("%7.3f | %10.3f\n", celsius, fahr);
        celsius = celsius + step;
    }
}
