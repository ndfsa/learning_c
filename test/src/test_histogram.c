#include "histogram.h"
#include <assert.h>
#include <stdio.h>
#include <string.h>

main()
{
	int counter1[50];
	int counter2[128];
	memset(counter1, 0, sizeof(int) * 50);
	word_length_count("hello world this is a test woohoo", counter1, 50);
	histogram(counter1, 50);
	vhistogram(counter1, 50);

	memset(counter2, 0, sizeof(int) * 50);
	frequency_count("hello world this is another test", counter1);
	histogram(counter1, 128);
	vhistogram(counter1, 128);

	return 0;
}
