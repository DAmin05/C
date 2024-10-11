
# The default rule to build the program
all: second  

second: second.c  
	gcc second.c -g -Wall -Werror -fsanitize=address -lm -std=c11 -o second  


# Clean rule to remove object files and the executable
clean:
	rm -f second  
# Replace 'first' with the name of the executable for each directory