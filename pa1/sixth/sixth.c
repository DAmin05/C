#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_WORD_LEN 100
#define MAX_SENTENCE_LEN 1000


void convertPigLatin(char word[]) {
    int len = strlen(word);
    if (tolower(word[0]) == 'a' || tolower(word[0]) == 'e' || tolower(word[0]) == 'i' || tolower(word[0]) == 'o' || tolower(word[0]) == 'u')
    {
        printf("%syay", word);
    }
    else
    {
        int firstVowelPos = -1;
  
        for (int i = 0; i < len; i++) {
            if (tolower(word[i]) == 'a' || tolower(word[i]) == 'e' || tolower(word[i]) == 'i' || tolower(word[i]) == 'o' || tolower(word[i]) == 'u') {
                firstVowelPos = i;
                break;
            }
        }
        
        if (firstVowelPos == -1)
        {
            printf("%say", word);
        }
        else
        {
            for (int i = firstVowelPos; i < len; i++)
            {
                printf("%c", word[i]);
            }
            for(int i = 0; i < firstVowelPos; i++)
            {
                printf("%c", word[i]);
            }
            printf("ay");
        }
    }
}


int main(int argCount, char *args[]) {

    if (argCount < 2) 
    {
        return 0;
    }

    char inputSentence[MAX_SENTENCE_LEN] = "";

    for (int i = 1; i < argCount; i++) {
        strcat(inputSentence, args[i]);
        //adding spaces
        if (i < argCount - 1) {
            strcat(inputSentence, " ");
        }
    }

    char *word = malloc(argCount);
    int index = 0;
    
    for (int i = 0; inputSentence[i] != '\0'; i++) 
    {
        if (inputSentence[i] != ' ')
        {
            word[index++] = inputSentence[i];
        }
        else
        {
            word[index] = '\0';
            convertPigLatin(word);
            printf(" ");
            index = 0;
        }
    }
    
    word[index] = '\0';
    convertPigLatin(word);
    printf("\n");

    return 0;
}
