all: eighth

eighth: eighth.c
	gcc eighth.c -g -Wall -Werror -fsanitize=address -std=c11 -o eighth

clean:
	rm -f eighth