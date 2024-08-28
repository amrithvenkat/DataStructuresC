// Linked list using head pointer in the main function
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node
{
    int data;
    struct Node *next;

} Node;

void printList(Node **head)
{
    printf("\nThe list is : \n");
    Node *temp = *head;
    while (temp)
    {
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void addNode(Node **head, int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    if (*head == NULL)
    {
        *head = newNode;
    }
    else
    {
        Node *temp = *head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void main()
{
    int choice, num;
    Node *head = NULL;
    do
    {
        printf("\nEnter choice..\n1. Add data \n2. Delete : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter data:");
            scanf("%d", &num);
            addNode(&head, num);
            printList(&head);
            break;

        default:
            printf("Invalid choice. \n");
            printList(&head);
            break;
        }

    } while (choice != 0);
}