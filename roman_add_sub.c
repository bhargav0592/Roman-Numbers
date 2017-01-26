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

/*
 * String Should contain only I,V,X,L,C,D,M characters.
*/
int validate_input_string(char *temp) {
	char *input;
	int len;

	input = temp;
	len = strlen(input);
	if (len == 0)
		return -1;
	for (int i = 0; i < len; i++) {
		if (input[i] != 'I' && input[i] != 'V'
			&& input[i] != 'X' && input[i] != 'L'
			&& input[i] != 'C' && input[i] != 'D'
			&& input[i] != 'M') {
			return -1;
		}
	}
	return 0;
}

int main(int argc, char *argv[]) {
	if (argc != 4) {
		printf("Please follow the instructions:\n");
		usage();
		return -1;
	}

	char *opt, *str1, *str2;
	int ret;

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

	if (str1)
		ret = validate_input_string(str1);
	else {
		printf("Input String1 is NULL\n");
		return -1;
	}

	if (ret) {
		printf("Input (%s) should contain only roman numbers\n", str1);
		return ret;
	}

	if (str2)
		ret = validate_input_string(str2);
	else {
		printf("Input String2 is NULL\n");
		return -1;
	}

	if (ret) {
		printf("Input (%s) should contain only roman numbers\n", str2);
		return ret;
	}

	str1 = strdup(str1);
	str2 = strdup(str2);

	printf("Input 1 : %s\nInput 2 : %s\n", str1, str2);
	goto out;

out:
	if (str1)
		free(str1);
	if (str2)
		free(str2);

return 0;
}
