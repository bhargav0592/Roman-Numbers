#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void usage() {
	printf("./roman_add_sub <opt> <str1> <str2>\n");
	printf("<opt>  : Takes a number; 1 means addition; 2 means subtraction.\n");
	printf("<str1> : First Roman number (in string format)\n");
	printf("<str2> : Second Roman number (in string format)\n");
	return ;
}


int main(int argc, char *argv[]) {
	if (argc != 4) {
		printf("Please follow the instructions:\n");
		usage();
		return -1;
	}

	char *opt, *str1, *str2;

	opt = argv[1];
	str1 = argv[2];
	str2 = argv[3];
	(void) str1;
	(void) str2;
	if (strlen(opt) != 1 || (opt[0] != '1' && opt[0] != '2')) {
		printf("Invalid option\n");
		usage();
		return -1;
	}


return 0;
}
