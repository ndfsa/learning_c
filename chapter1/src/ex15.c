#include <stdio.h>

#define LOWER 0
#define UPPER 300
#define STEP 20

int ftoc(int);

main()
{
	/* Rewrite the temperature conversion program of Section 1.2 to use a function for conversion.
	 * */
	int fahr, celsius;

	fahr = LOWER;
	while (fahr <= UPPER)
	{
		celsius = ftoc(fahr);
		printf("%d\t%d\n", fahr, celsius);
		fahr = fahr + STEP;
	}
}

int ftoc(int fahr)
{
	return 5 * (fahr - 32) / 9;
}
