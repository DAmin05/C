#include <stdio.h>
#include <stdlib.h>

//from part 8
struct Node {
    int value;
    struct Node *leftNode, *rightNode;
};

//from part 8
struct Node* createNode(int value) {
    struct Node* temp = malloc(sizeof(struct Node));
    temp->value = value;
    temp->leftNode = NULL;
    temp->rightNode = NULL;
    return temp;
}

//from part 8
void insertNode(struct Node** node, int value, int height) {
    if (*node == NULL) {
        *node = createNode(value);
        printf("inserted %d\n", height);
    } else if (value == (*node)->value) {
        printf("duplicate\n");
    } else if (value > (*node)->value) {
        insertNode(&((*node)->rightNode), value, height + 1);
    } else {
        insertNode(&((*node)->leftNode), value, height + 1);
    }
}

//from part 8
void searchNode(struct Node** node, int value, int height) {
    if (*node == NULL) {
        printf("absent\n");
    } else if (value == (*node)->value) {
        printf("present %d\n", height);
    } else if (value > (*node)->value) {
        searchNode(&((*node)->rightNode), value, height + 1);
    } else {
        searchNode(&((*node)->leftNode), value, height + 1);
    }
}

//from part 8
void freeMemory(struct Node* root) {
    if (root != NULL) {
        freeMemory(root->leftNode);
        freeMemory(root->rightNode);
        free(root);
    }
}

//find successor
struct Node* successor(struct Node* node) {
    node = node->rightNode;
    while (node->leftNode != NULL) {
        node = node->leftNode;
    }
    return node;
}

struct Node* deletion(struct Node* node , int value)
{
    if(node == NULL)
    {
        printf("fail\n");
        return node;
    }
    else if(value > node->value)
    {
        node->rightNode = deletion(node->rightNode, value);
    }
    else if(value < node->value)
    {
        node->leftNode = deletion(node->leftNode, value);
    }
    else
    {
        if(node->rightNode == NULL)
        {
            struct Node* temp = node->leftNode;
            printf("success\n");
            free(node);
            return temp;
        }
        else if(node->leftNode == NULL)
        {
            struct Node* temp = node->rightNode;
            printf("success\n");
            free(node);
            return temp;
        }
        else //2 children Node
        {
            struct Node* temp = successor(node); ////////////////////
            node->value = temp->value;
            node->rightNode = deletion(node->rightNode , temp->value);
        }
    }

    return node;
}

//from part 8
int main(int argCount, char* args[]) {
    if (argCount != 2) 
    {
        return 0;
    }

    FILE* inputFile = fopen(args[1], "r");
    if (inputFile == NULL) 
    {
        return 0;
    }

    struct Node* root = NULL;
    char ins_search;
    int value;

    while (fscanf(inputFile, "%c\t%d\n", &ins_search, &value) == 2) {
        if (ins_search == 'i') 
        {
            insertNode(&root, value, 1);
        } else if (ins_search == 's') 
        {
            searchNode(&root, value, 1);
        } else if (ins_search == 'd') 
        {
            root = deletion(root, value);
        }
    }

    freeMemory(root);
    fclose(inputFile);
}
