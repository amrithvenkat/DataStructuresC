// using head pointer globally
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// define Node Structure and its elements
typedef struct Node
{
    int data;
    struct Node *next;

} Node;

Node *head = NULL; // Define head Node

// Function Protoypes.
void printList();
void freeList();
void addNode(int);
void del(int);
int isempty();

void printList()
{
    printf("\nThe list is : \n");
    Node *temp = head;
    while (temp != NULL)
    {
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void addNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void freeList()
{
    if (head == NULL)
    {
        return; // List is already empty
    }

    Node *current;

    while (head != NULL) // traverse and free elements
    {
        current = head;
        head = head->next;
        printf("Freeing node with data: %d\n", current->data);
        free(current);
    }
    head = NULL;
}

void del(int num)
{
    Node *prev = NULL, *current = head;
    if (head->data == num)
    {
        Node *temp = head;
        head = head->next;
        printf("The deleted data is %d\n", temp->data);
        free(temp);
    }
    else
    {
        while ((current != NULL) && (current->data != num)) // traverse until condition is met
        {
            prev = current;
            current = current->next;
        }

        if (current != NULL && current->data == num) 
        {
            prev->next = current->next;
            printf("The deleted data is %d\n", current->data);
            free(current);
        }
        else
        {
            printf("Data %d is not in the list\n", num);
        }
    }

    printList();
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
    int choice, num;

    do
    {
        printf("\nEnter choice..\n1. Add data\n2. Delete data : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 0:
            continue;

        case 1:
            printf("Enter data:");
            scanf("%d", &num);
            addNode(num);
            printList();
            break;

        case 2:
            if (!isempty())
            {
                printf("\nEnter the element to be deleted :");
                scanf("%d", &num);
                del(num);
            }
            else
                printf("\nLIST is EMPTY");
            break;

        default:
            printf("Invalid choice. \n");
            printList();
        }

    } while (choice != 0);
    freeList();
}