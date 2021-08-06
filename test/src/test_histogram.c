#include "histogram.h"
#include <assert.h>
#include <stdio.h>

main()
{
	int counter1[50];
	char buf[1024];
	int i;
	char c;

	for (i = 0; i < 50; i++)
	{
		counter1[i] = 0;
	}
	i = 0;
	while ((c = getchar()) != EOF)
	{
		if (i == 1023)
		{
			word_length_count(buf, counter1, 50);
			i = 0;
		}
		buf[i++] = c;
	}
	if (i < 1023)
	{
		buf[i] = '\0';
		word_length_count(buf, counter1, 50);
	}
	histogram(counter1, 50);
	return 0;
}
