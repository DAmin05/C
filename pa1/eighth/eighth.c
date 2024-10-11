#include <stdio.h>
#include <stdlib.h>

struct Node{
    int value;
    struct Node *leftNode , *rightNode;
};

struct Node* createNode(int value)
{
    struct Node* temp = malloc(sizeof(struct Node));
    temp->value = value;
    temp->leftNode = NULL;
    temp->rightNode = NULL;
    return temp;
}

void insertNode(struct Node** node , int value , int height)
{
    if(*node == NULL)
    {
        *node = createNode(value);
        printf("inserted %d\n" , height);
    }
    else if(value == (*node)->value)
    {
        printf("duplicate\n");
    }
    else if(value > (*node)->value)
    {
        insertNode(&((*node)->rightNode) , value , height + 1);
    }
    else
    {
        insertNode(&((*node)->leftNode) , value , height + 1);
    }

}

void searchNode(struct Node** node , int value , int height)
{
    if(*node == NULL)
    {
        printf("absent\n");
    }
    else if(value == (*node)->value)
    {
        printf("present %d\n" , height);
    }
    else if(value > (*node)->value)
    {
        searchNode(&((*node)->rightNode) , value , height + 1);
    }
    else
    {
       searchNode(&((*node)->leftNode) , value , height + 1);
    }
}

void freeMemory(struct Node* root)
{
    if(root != NULL)
    {
        freeMemory(root->leftNode);
        freeMemory(root->rightNode);
        free(root);
    }
}

int main(int argCount , char *args[])
{
    if(argCount != 2)
    {
        return 0;
    }

    FILE *inputFile = fopen(args[1] , "r");
    if(inputFile == NULL)
    {
        return 0;
    }

    struct Node *root = NULL;
    char ins_search;
    int value;

    while(fscanf(inputFile , "%c\t%d\n" , &ins_search , &value) == 2)
    {
        if(ins_search == 'i')
        {
            insertNode(&root , value , 1); //root inserting at height 1
        }
        else if(ins_search == 's')
        {
            searchNode(&root , value , 1);
        }
    }

    freeMemory(root);
    fclose(inputFile);
}