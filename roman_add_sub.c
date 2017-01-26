#include <stdio.h>
#include <stdlib.h>

void usage() {
	printf("./roman_add_sub <opt> <str1> <str2>\n");
	printf("<opt>  : Takes a number; 1 means addition; 2 means subtraction.\n");
	printf("<str1> : First Roman number (in string format)\n");
	printf("<str2> : Second Roman number (in string format)\n");
	return ;
}


int main(int argc, char *agrv[]) {
	if (argc != 4) {
		printf("Please follow the instructions:\n");
		usage();
		return -1;
	}

return 0;
}
