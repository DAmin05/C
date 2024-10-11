#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define hashSize 1000 //size of hashtable

//defining Node
struct Node
{
    int value;
    struct Node* next;
};

//Initializing hashTable of hashSize
struct Node* hashTable[hashSize];

// Calculating hash key
int hashKey(int key)
{
    if(key < 0)
    {
        return (key % hashSize + hashSize) % hashSize; //if key is negative number, then make it positive first and then calculate the key
    }
    else
    {
        return key % hashSize; //normal calculation of key
    }
}

bool search(int value)
{
    int index = hashKey(value);
    struct Node* current = hashTable[index];

    while(current != NULL)
    {
        if(current->value == value)
        {
            return true; //finds duplicates
        }
        current = current->next;
    }
    return false; //no duplicates present
}

int main(int argCount , char *files[])
{
    //checking if args size is 2
    if(argCount != 2)
    {
        return 0;
    }

    //reading file
    FILE* inputFile = fopen(files[1] , "r");
    if(inputFile == NULL)
    {
        printf("error");
        return 0;
    }

    char ins_search;
    int value;
    while(fscanf(inputFile , "%c\t%d\n" , &ins_search , &value) == 2)
    {
        if(ins_search == 'i')
        {
            int key = hashKey(value);

            // Check if the value is already present in the hash table
            if (search(value)) {
                printf("duplicate\n");
                return 0;
            }

            // Creating new node with the value
            struct Node* new_node = malloc(sizeof(struct Node));
            new_node->value = value;
            new_node->next = hashTable[key];  // Insert at the head of the linked list
            hashTable[key] = new_node;        // Update the bucket pointer to the new node
            printf("inserted\n");
        }
        else if(ins_search == 's')
        {
            if(search(value))
            {
                printf("present\n");
            }
            else
            {
                printf("absent\n");
            }
        }
    }

    fclose(inputFile);

    //freeing the memory
    for (int i = 0; i < hashSize; i++) {
        struct Node* current = hashTable[i];
        while (current != NULL) {
            struct Node* temp = current;
            current = current->next;
            free(temp);
        }
    }

    return 0;
}