#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void usage() {
	printf("./roman_add_sub <opt> <str1> <str2>\n");
	printf("<opt>  : Takes a number; 1 means addition; 2 means subtraction.\n");
	printf("<str1> : First Roman number (in string format)\n");
	printf("<str2> : Second Roman number (in string format)\n");
	return ;
}

char *strrev(char *str)
{
      char *p1, *p2;

      if (! str || ! *str)
            return str;
      for (p1 = str, p2 = str + strlen(str) - 1; p2 > p1; ++p1, --p2)
      {
            *p1 ^= *p2;
            *p2 ^= *p1;
            *p1 ^= *p2;
      }
      return str;
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

char *Map1_keys[]   = {"IV",   "IX",    "XL"  , "XC",    "CD",   "CM"};
char *Map1_values[] = {"IIII", "VIIII", "XXXX", "LXXXX", "CCCC", "DCCCC"};

char *expand_string(char *input) {
	int len, i = 0, index = 0;
	bool found = false;
	char tmp[2] = {'\0', '\0'};
	char *output;

	len = strlen(input);
	output = (char *)calloc(1, 5*len*sizeof(char));
	while (i < len-1) {
		strncpy(tmp, input+i, 2);
		for (int j = 0; j < 6; j++) {
			if (strcmp(Map1_keys[j], tmp) == 0) {
				found = true;
				index = j;
				break;
			}
		}
		printf("(expand_string, i : %d ) Value of found : %d\n", i, found);
		if (found) {
			output = strcat(output, Map1_values[index]);
			i = i+2;
		} else {
			output = strncat(output, input+i, 1);
			i = i+1;
		}
		found = false;
		tmp[0] = '\0';
	}
	if (i == len-1) {
		output = strncat(output, input+len-1, 1);
	}
	return output;
}


char roman_nos[] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};

int get_roman_indx(char A) {
	for (int i = 0; i < 7; i++) {
		if (roman_nos[i] == A)
			return i;
	}
	return -1;
}

bool A_greater_than_B(char A, char B) {
	int indxA;
	int indxB;

	indxA = get_roman_indx(A);
	indxB = get_roman_indx(B);

	if (indxA > indxB)
		return true;
	return false;
}

int partition(char *input, int low, int high) {
	int pivot, wall;
	char temp;

	pivot = high;
	wall = low - 1;
	for (int i = low; i < high; i++) {
		if (A_greater_than_B(input[i], input[pivot])) {
			//Do Nothing
		} else {
			wall++;
			temp = input[wall];
			input[wall] = input[i];
			input[i] = temp;
			//printf("Swaped indexex %d with %d\n", wall, i);
		}
	}
	wall++;
	temp = input[wall];
	input[wall] = input[pivot];
	input[pivot] = temp;
	return wall;
}

void quick_sort(char *input, int low, int high) {
	if (low < high) {
		int pivot;

		pivot = partition(input, low, high);
		quick_sort(input, low, pivot-1);
		quick_sort(input, pivot+1, high);
	}
}

void sort_the_string(char *input) {
	int len;

	len = strlen(input);

	quick_sort(input, 0, len-1);
}

int main(int argc, char *argv[]) {
	if (argc != 4) {
		printf("Please follow the instructions:\n");
		usage();
		return -1;
	}

	char *opt, *str1, *str2;
	char *str1_exp = NULL, *str2_exp = NULL;
	char *big_str = NULL;
	int ret;

	(void) str2_exp;
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

	if (opt[0] == '1') {
		/* addition */
		/* 1. expantion */
		str1_exp = expand_string(str1);	
		printf("Expanded string : %s\n", str1_exp);

		str2_exp = expand_string(str2);
		printf("Expanded string :%s\n", str2_exp);

		/* 2. Concatenation */

		big_str = (char *)calloc(1, strlen(str1_exp) + strlen(str2_exp) + 1);
		big_str = strcpy(big_str, str1_exp);
		big_str = strcat(big_str, str2_exp);

		printf("Big String : %s\n", big_str);
		/* 3. Sort */
		sort_the_string(big_str);
		big_str = strrev(big_str);
		printf("Big String (after sort) : %s\n", big_str);


		/* 4. Compression */

	} else {
		/* subtraction */

	}


	goto out;

out:
	if (str1)
		free(str1);
	if (str2)
		free(str2);
	if (str1_exp)
		free(str1_exp);
	if (str2_exp)
		free(str2_exp);


return 0;
}

