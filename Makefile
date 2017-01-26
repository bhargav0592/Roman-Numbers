all: roman_add_sub

roman_add_sub:
	gcc -Wall -Werror roman_add_sub.c -o roman_add_sub

clean:
	rm -rf roman_add_sub
