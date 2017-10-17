#include <stdio.h>
#include <stdlib.h>

typedef struct NODE
{
    char data;
    struct Node* link;
}Node;

Node *stackPtr = NULL;

void push(char);
char pop();
void print();

int emptyStack = 0, not_balanced = 0;

int main()
{
    char str[20], last_char;
    int i;

    scanf("%s", str);
    for (i=0; i<strlen(str); i++)
    {
        if (str[i] == '{' || str[i] == '[' || str[i] == '(')
        {

            push(str[i]);

        }

        else if (str[i] == '}')
        {
            last_char = pop();
            if (last_char != '{')
            not_balanced = 1;
        }

        else if (str[i] == ']')
        {
            last_char = pop();
            if (last_char != '[')
            not_balanced = 1;
        }

        else if (str[i] == ')')
        {
            last_char = pop();
            if (last_char != '(')
            not_balanced = 1;
        }

        else
        {
            // Do nothing
        }

    }

    if (not_balanced == 0 && emptyStack == 1)
        printf("BALANCED");

    else
        printf("NOT BALANCED");
    return 0;
}

void push (char num)
{
    emptyStack = 0;
    Node *current = (Node*) malloc(sizeof(Node));

    if (stackPtr == NULL)
    {
        stackPtr = current;
        current->data = num;
        current->link = NULL;
    }

    else
    {
        current->data = num;
        current->link = stackPtr;
        stackPtr = current;
    }
}

char pop ()
{
    char element;

    Node *temp = NULL;
    temp = stackPtr;

    element = stackPtr->data;

    if (stackPtr->link == NULL)
    {
        emptyStack = 1;
        free(stackPtr);
    }

    else
    {
        stackPtr = stackPtr->link;
        free(temp);
    }

    return element;
}

void print()
{
    Node *temp = stackPtr;

    while (temp != NULL)
    {
        printf("%i\n", temp->data);
        temp = temp->link;
    }
}
