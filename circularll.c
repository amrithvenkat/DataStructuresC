// CIRCULAR SINGLE LINKED LIST
#include <stdio.h>
#include <stdlib.h>

// define Node Structure and its elements
typedef struct Node
{
  int data;
  struct Node *next;

} Node;

Node *head = NULL; // Define head Node

// Function Protoypes.
void addNode();
void freeList();
void printList();
void insert();
void del(int);
int isempty();

void freeList()
{
  if (head == NULL)
  {
    return; // List is already empty
  }

  Node *temp;
  Node *current = head;

  // Loop through and free all nodes except the last one
  while (current->next != head)
  {
    temp = current;
    current = current->next; // Move to the next node
    printf("Freeing node with data: %d\n", temp->data);
    free(temp); // Free the current node
  }

  // Free the last node (which points to itself)
  printf("Freeing last node with data: %d\n", current->data);
  free(current);

  // Set the head to NULL as the list is now empty
  head = NULL;
}


void addNode()
{
  int num, numElem;
  Node *newNode; // Only one pointer

  printf("\nEnter the number of elements: ");
  scanf("%d", &numElem);

  if (numElem <= 0)
  {
    printf("Invalid number of elements.\n");
    return;
  }

  // Create the first node and set it as the head
  printf("\nEnter the data: ");
  scanf("%d", &num);

  head = (Node *)malloc(sizeof(Node));
  if (!head)
  {
    printf("Memory allocation failed\n");
    return;
  }

  head->data = num;
  head->next = head; // Circular link to itself
  newNode = head;    // Use 'temp' to manage further nodes

  // Loop to create the remaining nodes
  for (int i = 1; i < numElem; i++)
  {
    printf("\nEnter the data: ");
    scanf("%d", &num);

    // Allocate and set up new node
    newNode->next = (Node *)malloc(sizeof(Node));
    newNode = newNode->next; // Move temp to the new node
    if (!newNode)
    {
      printf("Memory allocation failed\n");
      return;
    }

    newNode->data = num;
    newNode->next = head; // Maintain the circular link by pointing to head
  }

  printList(); // Assuming this function exists to print the circular list
}

void printList()
{
  Node *temp;
  temp = head;
  if (head == NULL)
  {
    printf("LIST is EMPTY");
    return;
  }
  while (temp->next != head)
  {
    printf("%d->", temp->data);
    temp = temp->next;
  }
  printf("%d->", temp->data);
  printf("%d", temp->next->data);
}

void insert()
{
  int choice, num, numAfter;
  Node *newNode, *lastNode;
  printf("\nEnter the number:");
  scanf("%d", &num);
  if (head != NULL)
  {
    printf("\nchoose where to insert:\n1.first\n2.middle\n3.last\n0.exit:");
    scanf("%d", &choice);
  }
  else
  {
    choice = 1;
  }
  switch (choice)
  {
  case 1:
    if (head == NULL) // the list is empty
    {
      head = (Node *)malloc(sizeof(Node));
      head->data = num;
      head->next = head;
    }
    else // the list has an existing first element.
    {
      lastNode = head;
      while (lastNode->next != head)
      {
        lastNode = lastNode->next;
      }
      newNode = (Node *)malloc(sizeof(Node));
      newNode->data = num;
      newNode->next = head;
      head = newNode;
      lastNode->next = head;
    }
    printList();
    break;

  case 2:
    printf("\nEnter the element you want to insert after:");
    scanf("%d", &numAfter);
    lastNode = head;
    while (lastNode->data != numAfter)
    {
      lastNode = lastNode->next;
    }
    if ((lastNode->data != numAfter) && (lastNode->next == head))
    {
      printf("\nCheck the value");
    }
    else
    {
      newNode = (Node *)malloc(sizeof(Node));
      newNode->data = num;
      newNode->next = lastNode->next;
      lastNode->next = newNode;
    }
    printList();
    break;

  case 3:
    lastNode = head;
    while (lastNode->next != head)
    {
      lastNode = lastNode->next;
    }
    newNode = (Node *)malloc(sizeof(Node));
    newNode->data = num;
    newNode->next = head;
    lastNode->next = newNode;
    printList();
    break;

  default:
    printf("\nCheck the value:");
  }
}

void del(int num)
{
  Node *temp, *prev, *lastNode;
  temp = lastNode = head;
  if (head->data == num) /* node to be deleted is first/last node*/
  {
    if (head->next == head) // and its the only node
    {
      printf("Freeing only node with data: %d\n", head->data);
      free(head);
      head = NULL;
    }
    else // if it is the first/last node spefically among many others
    {
      while (lastNode->next != head)
      {
        lastNode = lastNode->next;
      }
      head = head->next;
      lastNode->next = head;
      printf("Freeing the first/last node with data: %d\n", temp->data);
      free(temp);
    }
  }
  else // the node is somewhere in between
  {
    while ((temp->data != num) && (temp->next != head)) // traverse to element
    {
      prev = temp;
      temp = temp->next;
    }
    if (temp->data == num)
    {
      prev->next = temp->next;
      printf("\nthe deleted data is %d\n", temp->data);
      free(temp);
    }
    else
    {
      printf("data is not in the list");
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

int main()
{
  int ch, a;
  addNode();
  do
  {
    printf("\nEnter your choice:\n1.Insert\n2.Delete\n0. Exit:");
    scanf("%d", &ch);
    switch (ch)
    {
    case 0:
      continue;

    case 1:
      insert();
      break;

    case 2:
      if (!isempty())
      {
        printf("\nEnter the element to be deleted :");
        scanf("%d", &a);
        del(a);
      }
      else
        printf("\nLIST is EMPTY");
      break;

    default:
      printf("\nInvalid choice:");
    }
  } while (ch != 0);

  freeList();
  return 0;
}
