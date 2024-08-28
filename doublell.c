// Double linked list
#include <stdio.h>
#include <stdlib.h>

// define Node Structure and its elements
typedef struct Node
{
	int data;
	struct Node *next;
	struct Node *prev;
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

	Node *current;

	// Loop through and free all nodes except the last one
	while (head != NULL)
	{
		current = head;
		head = head->next; // Move to the next node
		printf("Freeing node with data: %d\n", current->data);
		free(current); // Free the current node
	}

	// Set the head to NULL as the list is now empty
	head = NULL;
}

void addNode()
{
	int num, numElem;
	Node *newNode, *prevNode;

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

	head->data = num; // Assign num and set prev and next to NULL
	head->prev = NULL;
	head->next = NULL;
	newNode = head; // Use 'temp' to manage further nodes
	prevNode = head;

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
		newNode->next = NULL;
		newNode->prev = prevNode;
	}
	printList();
}

void printList()
{
	Node *temp = NULL;
	temp = head;
	if (head == NULL)
	{
		printf("LIST is EMPTY\n");
		return;
	}
	else
	{
		printf("NULL");
		while (temp->next != NULL)
		{
			printf("<===>%d", temp->data);
			temp = temp->next;
		}
		printf("<===>%d", temp->data);
	}
	printf("<===>NULL\n");
}

void insert()
{
	int choice, num, numAfter;
	Node *temp, *temp1;

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
		if (head == NULL) // List has no elements
		{
			head = (Node *)malloc(sizeof(Node));
			if (!head)
			{
				printf("Memory allocation failed\n");
				return;
			}
			head->data = num;
			head->prev = NULL;
			head->next = NULL;
		}
		else // List has some elements.
		{
			temp = (Node *)malloc(sizeof(Node));
			temp->data = num;
			temp->next = head;
			temp->prev = NULL;
			head->prev = temp;
			head = temp;
		}
		break;
	case 2:
		printf("\nEnter the element you want to insert after:");
		scanf("%d", &numAfter);
		temp = head;
		while (temp->data != numAfter) // traverse the list upto the number
		{
			temp = temp->next;
		}
		temp1 = (Node *)malloc(sizeof(Node));
		temp1->data = num;
		if (temp->next != NULL)
		{
			temp1->next = temp->next;
			temp->next->prev = temp1;
		}
		else // Adding element after the last element but option2 was selected.
		{
			temp1->next = NULL;
		}
		temp1->prev = temp;
		temp->next = temp1;
		break;

	case 3:
		temp = head;
		while (temp->next != NULL) // traverse
		{
			temp = temp->next;
		}
		temp1 = (Node *)malloc(sizeof(Node));
		temp1->data = num;
		temp1->next = NULL;
		temp1->prev = temp;
		temp->next = temp1;
		break;
	default:
		printf("\nCheck the value:");
	}
	printList();
}

void del(int num)
{
	Node *temp, *temp1;
	temp = head;
	if (head == NULL)
	{
		printf("The list is empty\n");
		return;
	}
	if (head->data == num) // the number is the first element.
	{
		if ((head->next == NULL) && (head->prev == NULL)) // its the only node.
		{
			printf("\nthe deleted data is %d\n", head->data);
			free(head);
			head = NULL;
		}
		else // there are other nodes.
		{
			head = head->next;
			head->prev = NULL;
			printf("\nthe deleted data is %d\n", head->data);
			free(temp);
		}
	}
	else // the number is in the list somewhere
	{
		while ((temp->data != num) && (temp->next != NULL)) // traverse until conditions
		{
			temp1 = temp;
			temp = temp->next;
		}
		if (temp->data == num) // Number is found
		{
			if (temp->next == NULL) // Check if its the end of list
			{
				temp1->next = NULL;
				printf("\nthe deleted data is %d\n", temp->data);
				free(temp);
			}
			else
			{
				temp1->next = temp->next;
				temp->next->prev = temp1;
				printf("\nthe deleted data is %d\n", temp->data);
				free(temp);
			}
		}
		else
		{
			printf("data is not in the list : ");
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
	int choice, num;
	addNode();
	do
	{
		printf("\nEnter your choice:\n1.Insert\n2.Delete\n0. Exit:");
		scanf("%d", &choice);
		switch (choice)
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
				scanf("%d", &num);
				del(num);
			}
			else
				printf("\nLIST is EMPTY");

			break;

		default:
			printf("\ncheck the value:");
		}
	} while (choice != 0);
	freeList();
	return 0;
}
