#include <stdio.h>
#include <stdlib.h>

// HEAD -> 1 -> 2 -> NULL

struct Node
{
	int data;
	struct Node* next;
	struct Node* prev;
};

struct Node* create_node(int node_c)
{
	struct Node* head = malloc(sizeof(struct Node));
	struct Node* current = malloc(sizeof(struct Node));
	struct Node* prev = malloc(sizeof(struct Node));
	prev = NULL;
	current = head;
	for(int i=1;i<node_c+1;i++)
	{
		struct Node* oneNode = malloc(sizeof(struct Node));
		oneNode->data = i;
		current->next = oneNode;
		current->prev = prev;
		current = current->next;
		prev = current;
	}
	current->next = NULL;
	head->prev = current;
	return head;
}

void print_node(struct Node* head)
{
	struct Node* cr;
	cr = head;
	while(cr->next != NULL)
	{
		printf("d = %d\n",cr->data);
		cr=cr->next;
	}
	cr = head;
	while(cr->prev != NULL)
	{
		printf("d = %d\n",cr->data);
		cr=cr->next;
	}
}

void main()
{
	struct Node* myNode;

	myNode = create_node(5);
	print_node(myNode);
}
