#include <stdio.h>

main()
{
	/* Modify the temperature conversion program to print the table in reverse order, that is, from
	 * 300 degrees to 0.
	 * */

	float fahr, celcius;
	int lower, upper, step;

	printf("fahrenheit | celcius\n--------------------\n");

	lower = 0;
	upper = 300;
	step = 20;

	fahr = upper;

	while (fahr >= lower)
	{
		celcius = (5.0 / 9.0) * (fahr - 32.0);
		printf("%10.3f | %7.3f\n", fahr, celcius);
		fahr = fahr - step;
	}
}
