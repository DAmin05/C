#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argCount, char *argv[]) {
    if (argCount < 2) {
        return 0;
    }

    char *result = malloc(argCount);

    result[0] = '\0';

    for (int i = 1; i < argCount; i++) 
    {
        char tempChar[2]; // temporary string to hold the last char of the string because strcat accepts only strings, so last char has to be a string
        tempChar[0] = argv[i][strlen(argv[i]) - 1];
        tempChar[1] = '\0';
        strcat(result, tempChar);// Concatenate
    }

    printf("%s\n", result);

    free(result);

    return 0;
}
