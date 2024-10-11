# Simple Makefile without variables

# The default rule to build the program
all: first  # Replace 'first' with the name of the program for each directory

# Rule to build the 'first' executable (change the name accordingly)

#Werror turn all the warning into errors
#Wall give all the warnings
#fsanitize is error telling index out of bound
first: first.c  
	gcc first.c -g -Wall -Werror -fsanitize=address -lm -std=c11 -o first  



# Clean rule to remove object files and the executable
clean:
	rm -f first  
# Replace 'first' with the name of the executable for each directory
