#include <stdio.h>
#include <stdlib.h>
//#include <string.h>

//defining a Node
struct Node
{
    int value;
    struct Node* next;
};

//creating new node
struct Node* createNode(int value)
{
    struct Node* newNode = malloc(sizeof(struct Node));
    if(newNode == NULL)
    {
        exit(1);
    }
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

void deteleNode(struct Node** head , int value)
{
    struct Node* current = *head;
    struct Node* prev = NULL;

    //head has the same value
    if(current!= NULL && current->value == value)
    {
        *head = current->next;
        free(current);
        return;
    }

    //traversal of the link list
    while(current!=NULL && current->value != value)
    {
        prev = current;
        current = current->next;
    }

    //value is not in the list
    if(current == NULL)
    {
        return;
    }

    //deleting the node
    prev->next = current->next;
    free(current);
}

void insertSorted(struct Node** head , int value)
{
    struct Node* newNode = createNode(value);
    struct Node* current = *head;

    //checking for duplicates
    while(current != NULL)
    {
        if(current->value == value)
        {
            free(newNode); //does not insert any duplicate values
            return;
        }
        current = current->next;
    }
    
    //Insert at the head if list is empty or value is smallest
    if(*head == NULL || (*head)->value > value)
    {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    //traverse and insert at the correct position
    current = *head;
    while(current->next != NULL && current->next->value < value)
    {
        current = current->next;
    }
    newNode->next = current->next;
    current->next = newNode;
}

int main(int argsCount , char* args[])
{
    if(argsCount != 2)
    {
        printf("error\n");
        return 0;
    }

    FILE* inputFile = fopen(args[1] , "r");
    if(inputFile == NULL)
    {
        printf("error\n");
        return 0;
    }

    struct Node* head = NULL;
    char ins_del;
    int value;
    int isFileEmpty;

    while(fscanf(inputFile , "%c\t%d\n" , &ins_del , &value) == 2)
    {
        isFileEmpty = 0;
        if(ins_del == 'd')
        {
            deteleNode(&head , value);
        }
        else if(ins_del == 'i')
        {
            insertSorted(&head , value);
        }
    }
    fclose(inputFile);

    if(isFileEmpty)
    {
        printf("0\n");
    }
    else
    {
        int size = 0;
        struct Node* current = head;
        while(current != NULL)
        {
            size++;
            current = current->next;
        }
        printf("%d\n" , size);
        if(size>0)
        {
            struct Node* current = head;
            while(current != NULL)
            {
                printf("%d" , current->value);
                if(current->next != NULL)
                {
                    printf("\t");
                }
                current = current->next;
            }
            printf("\n");
        }
    }

    // Free the linked list memory
    struct Node* current = head;
    while (current != NULL) {
        struct Node* next = current->next;
        free(current);
        current = next;
    }
}