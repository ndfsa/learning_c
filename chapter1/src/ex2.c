#include <stdio.h>

main()
{
	/* Experiment to find out what happens when printf's argument contains \c where c is some
	 * character not listed above (page 8).
	 * */
	printf("\t\c\a\d\n");
}
