#include <stdio.h>
#include <stdlib.h>

// HEAD -> 1 -> 2 -> NULL

struct Node
{
	int data;
	struct Node* next;
};


struct Node* reverse_ll(struct Node* head)
{
	struct Node* cr;
	struct Node* tmp;
	struct Node* prev = NULL;
	cr = head;
	while(cr != NULL)
	{

		tmp = cr->next;
		cr->next = prev;
		prev = cr;
		cr = tmp;

	}
	return prev;
}

struct Node* create_node(int node_c)
{
	struct Node* head = malloc(sizeof(struct Node));
	struct Node* current = malloc(sizeof(struct Node));
	current = head;
	for(int i=1;i<node_c+1;i++)
	{
		struct Node* oneNode = malloc(sizeof(struct Node));
		oneNode->data = i;
		current->next = oneNode;
		current = current->next;
	}
	current->next = NULL;
	return head;
}

void print_node(struct Node* head)
{
	if(head == NULL)
	{
		printf("head is null\n");
		return;
	}
	while(head->next != NULL)
	{
		printf("d = %d\n",head->data);
		head=head->next;
	}
}

void main()
{
	struct Node* myNode;

	myNode = create_node(5);
	print_node(myNode);
	printf("Reversed ll \n");
	myNode = reverse_ll(myNode);
	print_node(myNode);
}
