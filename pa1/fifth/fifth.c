#include <stdio.h>
#include <stdlib.h>

int main(int argCount , char *args[])
{
    if(argCount != 2)
    {
        return 0;
    }

    //reading file
    FILE *inputfile = fopen(args[1] , "r");
    if(inputfile == NULL)
    {
        return 0;
    }

    int length; //length of matrix
    fscanf(inputfile , "%d" , &length);

    //allocating matrix memory
    int **matrix = malloc(length * sizeof(int*));
    for(int i=0 ; i<length ; i++)
    {
        matrix[i] = malloc(length * sizeof(int*));
        for (int j=0 ; j<length ; j++)
        {
            fscanf(inputfile , "%d" , &matrix[i][j]);
        }
    }
    //sum of the matrix columns/rows/diagonals
    int sum = 0;
    for(int i=0 ; i<length ; i++)
    {
        sum += matrix[0][i];
    }

    //array to keep track of numbers seen, 0 number not seen, 1 number is seen
    int *visited = malloc((length*length+1) * sizeof(int*));
    for (int i = 0; i <= length*length; i++) {
        visited[i] = 0;
    }

    int rowSum, colSum;
    for(int i=0 ; i<length ; i++)
    {
        rowSum = 0;
        colSum = 0;
        for(int j=0 ; j<length ; j++)
        {
            rowSum += matrix[i][j];
            colSum += matrix[j][i];

            if (matrix[i][j] < 1 || matrix[i][j] > length * length || visited[matrix[i][j]]) {
                free(visited);
                printf("not-magic");
                return 0;
            }
            visited[matrix[i][j]] = 1;
        }

        if(rowSum != sum || colSum != sum)
        {
            free(visited);
            printf("not-magic");
            return 0;
        }
    }
    int diagonalSum1=0 , diagonalSum2=0;
    for(int i=0,j=length-1 ; i<length ; i++,j--)
    {
        diagonalSum1 += matrix[i][i];
        diagonalSum2 += matrix[i][j];
    }

    if(diagonalSum1 != sum || diagonalSum1 != sum)
    {
        free(visited);
        printf("not-magic");
        return 0;
    }

    free(visited);
    printf("magic");

    for(int i=0 ; i<length ; i++)
    {
        free(matrix[i]);
    }
    free(matrix);
    fclose(inputfile);
    return 0;
}