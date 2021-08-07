#include <stdio.h>
#include "celcius.h"

/* Exercise 1-4 */
void ctof()
{
	float celcius;
	int lower, upper, step;

	lower = 0;
	upper = 300;
	step = 20;

	celcius = lower;
	/* print header table */
	printf("celcius | fahrenheit\n--------------------\n");

	while (celcius <= upper)
	{
		printf("%7.3f | %10.3f\n", celcius, to_fahrenheit((float)celcius));
		celcius = celcius + step;
	}
}

float to_fahrenheit(float celcius)
{
	return 1.8 * celcius + 32.0;
}
