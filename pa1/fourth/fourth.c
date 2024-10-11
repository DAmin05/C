#include <stdio.h>
#include <stdlib.h>

int** multiplyMatrices(int **matrix1 , int rowsMatrix1 , int colMatrix1 , int **matrix2 , int rowsMatrix2 , int colMatrix2)
{
    //if columns of Matrix1 is not equal to rows Matrix2 then return 0    
    if(rowsMatrix2 != colMatrix1)
    {
        printf("bad-matrices\n");
        exit(1);
    }

    //allocating memory
    int **resultMatrix = malloc(rowsMatrix1 * sizeof(int *));
    for (int i = 0; i < rowsMatrix1; i++) {
        resultMatrix[i] = malloc(colMatrix2 * sizeof(int));
    }

    //multiplication
    for(int i=0 ; i<rowsMatrix1 ; i++)
    {
        for(int j=0 ; j<colMatrix2 ; j++)
        {
            resultMatrix[i][j] = 0;
            for(int k=0 ; k<colMatrix1 ; k++)
            {
                resultMatrix[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
    return resultMatrix;
}

void freeMatrix(int **matrix , int rows)
{
    for(int i=0 ; i<rows ; i++)
    {
        free(matrix[i]);
    }
    free(matrix);
}

int main(int argCount , char *args[])
{
    if(argCount != 2)
    {
        return 0;
    }
    
    //reading file
    FILE *inputFile = fopen(args[1] , "r");
    if(inputFile == NULL)
    {
        return 0;
    }

    //reading and allocating memory for Matrix1
    int rowsMatrix1 , colMatrix1;
    fscanf(inputFile , "%d%d" , &rowsMatrix1 , &colMatrix1);
    int **matrix1 = malloc(rowsMatrix1 * sizeof(int *));
    for(int i=0 ; i<rowsMatrix1 ; i++)
    {
        matrix1[i] = (int *)malloc(colMatrix1 * sizeof(int));
    }
    //filling matrix with the numbers from file
    for(int i=0 ; i<rowsMatrix1 ; i++)
    {
        for(int j = 0 ; j<colMatrix1 ; j++)
        {
            fscanf(inputFile , "%d" , &matrix1[i][j]);
        }
    }

    //reading and allocating memory for Matrix2
    int rowsMatrix2 , colMatrix2;
    fscanf(inputFile , "%d%d" , &rowsMatrix2 , &colMatrix2);
    int **matrix2 = malloc(rowsMatrix2 * sizeof(int *));
    for(int i=0 ; i<rowsMatrix2 ; i++)
    {
        matrix2[i] = malloc(colMatrix2 * sizeof(int));
    }
    //filling matrix with the numbers from file
    for(int i=0 ; i<rowsMatrix2 ; i++)
    {
        for(int j = 0 ; j<colMatrix2 ; j++)
        {
            fscanf(inputFile , "%d" , &matrix2[i][j]);
        }
    }

    //multiply matrices
    int **resultMatrix = multiplyMatrices(matrix1 , rowsMatrix1 , colMatrix1 , matrix2 , rowsMatrix2 , colMatrix2);

    //printing resultMatrix
    for(int i=0 ; i<rowsMatrix1 ; i++)
    {
        for(int j=0 ; j<colMatrix2 ; j++)
        {
            printf("%d" , resultMatrix[i][j]);
            if (j<colMatrix2-1)
            {
                printf("\t");
            }
        }
        printf("\n");
    }

    //free the memory
    freeMatrix(matrix1 , rowsMatrix1);
    freeMatrix(matrix2 , rowsMatrix2);
    freeMatrix(resultMatrix , rowsMatrix1);

    fclose(inputFile);
    return 0;
}