#include "blanks.h"
#include <stdio.h>

main()
{
	char s[] = "a b c  d		e  	f   	g h  i   j";
	fold_blanks(s);
	printf("%s\n", s);
	return 0;
}
