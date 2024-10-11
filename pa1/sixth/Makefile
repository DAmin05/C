all: sixth

eighth: seventh.c
	gcc sixth.c -g -Wall -Werror -fsanitize=address -std=c11 -o sixth

clean:
	rm -f sixth