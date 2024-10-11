#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>


bool isPrime(int num)
{
    if(num == 0 || num == 1)
    {
        return false;
    }
    else
    {
        for (int i = 2 ; i <= sqrt(num) ; i++) 
        {
            if (num % i == 0) 
            {
                return false;
            }
        }
        return true;
    }
}


bool isTurncatable(int number)
{
    if(number <= 0) //if number is negative or zero, it can't be prime
    {
        return false;
    }
    else
    {
        while (number > 0)
        {
            if(!isPrime(number))
            {
                return false;
            }
            number /= 10;
        }
        return true;
    }
}

//argCount is length of arguments
//fileName[0] is first.out ~ ./first
//fileName[1] is input file
int main(int argCount , char *fileName[])
{
    if(argCount != 2)
    {
        printf("error\n"); //third file checks for error, so to be on safe side
        return 0;
    }

    FILE *inputFile = fopen(fileName[1] , "r"); //openning file in read mode

    if(inputFile == NULL) //checking if the file is null
    {
        printf("error\n");
        return 0;
    }

    int totalValues;
    fscanf(inputFile , "%d" , &totalValues);

    for (int i = 0; i < totalValues; i++)
    {
        int number; //numbers in file
        fscanf(inputFile , "%d" , &number); //reads number one by one from the file
        
        if(isTurncatable(number))
        {
            printf("yes\n");
        }
        else
        {
            printf("no\n");
        }
    }
    fclose(inputFile);
    return 0;
}

