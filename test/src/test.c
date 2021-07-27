#include <temperatures.h>
#include <input_output.h>
#include <stdio.h>

main ()
{
	ctof();
	ftoc();

	eof_val();

	char res[128];
	fold_blanks("a b    c 	 		 d 	 e			   f    g						h  i  j", res);
	printf("%s\n", res);
	return 0;
}
