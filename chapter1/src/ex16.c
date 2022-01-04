#include "ch1utils.h"
#include <stdio.h>
#define MAXLINE 1024

main()
{
	/* Revise the main routine of the longest-line program so it will correctly print the length of
	 * arbitrarily long input lines, and as much as possible of the text.
	 * */
	int len;
	int max;
	char line[MAXLINE];
	char longest[MAXLINE];

	max = 0;
	while ((len = getline(line, MAXLINE)) > 0)
		if (len > max)
		{
			max = len;
			copy(line, longest);
		}
	if (max > 0 && max < MAXLINE)
		printf("%s\n", longest);
	else if (max > 0)
		printf("%s...\n", longest);

	return 0;
}
