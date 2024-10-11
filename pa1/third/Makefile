all: third

third: third.c
	gcc third.c -g -Wall -Werror -fsanitize=address -std=c11 -o third

clean:
	rm -f third