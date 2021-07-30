#include "blanks.h"
#include <stdio.h>
#include <assert.h>
#include <string.h>

main()
{
	char s1[50];
	char s2[50];
	char s3[50];
	char s3_res[50];

	strcpy(s1, "hello world from the C programming language	\n");
	assert(count_blanks(s1) == 8);

	strcpy(s2, "a b c  d		e  	f   	g h  i   j");
	fold_blanks(s2);
	assert(strcmp(s2, "a b c d e f g h i j") == 0);

	strcpy(s3, "select\tthese\b\\things");
	encode(s3, s3_res);
	assert(strcmp("select\\tthese\\b\\\\things", s3_res) == 0);

	return 0;
}
