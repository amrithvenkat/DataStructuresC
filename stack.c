// Stack implementation using linked list
#include <stdio.h>
#include <stdlib.h>

// define Node Structure and its elements
typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node *top = NULL, *head = NULL; // define global nodes

// Function prototypes.
void push();
void pop();
int isempty();
void printList();
void freeList();

void freeList()
{
    while (!isempty())
    {
        printf("Freeing node with data: %d\n", top->data);
        pop();
    }
}

void push()
{
    int num;
    Node *temp;
    printf("\nEnter the data:");
    scanf("%d", &num);
    temp = (Node *)malloc(sizeof(Node));
    temp->data = num;
    temp->next = top;
    if (head == NULL)
    {
        head = temp;
    }
    top = temp;
}

void printList()
{
    Node *temp;
    temp = top;
    if (temp != NULL)
    {
        printf("\n");
        printf("TOP->");
        while (temp != NULL)
        {
            printf("%d->", temp->data);
            temp = temp->next;
        }
        printf("NULL");
    }
    else
        printf("\nList is empty");
}

void pop()
{
    Node *temp;
    temp = top;
    top = top->next;
    if (top == NULL)
    {
        head = NULL;
    }
    free(temp);
}

int isempty()
{
    if (head == NULL)
        return 1;
    else
        return 0;
}

void main()
{
    int choice;
    do
    {
        printf("\nEnter your choice:\n1.PUSH\n2.POP\n0.Exit:");
        scanf("%d", &choice);
        switch (choice)
        {

        case 0:
            continue;

        case 1:
            push();
            printList();
            break;

        case 2:
            if (!isempty())
            {
                pop();
                printList();
            }
            else
                printf("\nStack Underflow");
            break;

        default:
            printf("\nCheck the value:");
            break;
        }
    } while (choice != 0);
    freeList();
}
