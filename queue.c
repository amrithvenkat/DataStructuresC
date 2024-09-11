// Queue using linked list
#include <stdio.h>
#include <stdlib.h>

// define Node Structure and its elements
typedef struct Node
{
  int data;
  struct Node *next;
} Node;

Node *front = NULL, *rear = NULL;

// Function Protoypes
void enque();
void deque();
void printList();
int isempty();
void freeList();

void enque()
{
  int x;
  Node *temp = (Node *)malloc(sizeof(Node));

  printf("\nEnter the data:");
  scanf("%d", &x);

  temp->data = x;
  temp->next = NULL;

  if (front == NULL && rear == NULL)
  {
    front = rear = temp;
  }
  else if (rear != NULL)
  {
    rear->next = temp;
    rear = temp;
  }
}

void deque()
{
  Node *temp = front;
  if (front == rear) // If there's only one node
  {
    front = rear = NULL; // Set both front and rear to NULL
  }
  else
  {
    front = front->next; // Move front to the next node
  }
  printf("Dequeued element: %d\n", temp->data);
  free(temp); // Free the old front node
}

void printList()
{
  Node *temp;
  temp = front;
  printf("Front");
  while (temp != NULL)
  {
    printf(" <- %d", temp->data);
    temp = temp->next;
  }
  printf(" <- Rear");
}

int isempty()
{
  return (front == NULL && rear == NULL)
}

void freeList()
{
  while (!isempty())
  {
    printf("Freeing node with data: %d\n", front->data);
    deque();
  }
  return;
}

void main()
{
  int x;

  do
  {
    printf("\n1.ENQUE\n2.DEQUE\n0.Exit:");
    scanf("%d", &x);
    switch (x)
    {
    case 0:
      continue;

    case 1:
      enque();
      printList();
      break;

    case 2:
      if (!isempty())
      {
        deque();
        printList();
      }
      else
      {
        printf("\nQueue is empty");
      }
      break;

    default:
      printf("\nCheck your value...");
      break;
    }
  } while (x != 0);
  freeList();
}
