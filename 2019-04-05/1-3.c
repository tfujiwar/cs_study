#include <stdio.h>
#include <stdlib.h>

typedef struct LIST_NODE{
	int value;
	struct LIST_NODE *next;
} list_node;

void printList(list_node *node)
{
	printf("[ ");
	while (node != NULL) {
		printf("%d ", node->value);
		node = node->next;
	}
	printf("]\n");
}

void add(list_node *node, int value)
{
	list_node *new_node;
	new_node = (list_node*) malloc(sizeof(list_node));

	new_node->value = value;
	new_node->next = NULL;

	while (node->next != NULL) {
		node = node->next;
	}

	node->next = new_node;
}

list_node* delete(list_node *node, int index)
{
	list_node *new_head, *deleted_node;
	if (index == 0) {
		new_head = node->next;
		deleted_node = node;
	} else {
		new_head = node;
		for (int i = 0; i < index - 1; i++) {
			node = node->next;
		}
		if (node->next == NULL) {
			return new_head;
		}
		deleted_node = node->next;
		node->next = node->next->next;
	}
	free(deleted_node);
	return new_head;
}

int find(list_node *node, int index)
{
	for (int i = 0; i < index; i++) {
		node = node->next;
	}
	return node->value;
}

int main()
{
	list_node *node;
	node = (list_node*) malloc(sizeof(list_node));
	node->value = 0;
	node->next = NULL;

	for (int i = 1; i < 5; i++) {
		add(node, i);
		printf("Value %d was added: ", i);
		printList(node);
	}
	printf("\n");

	for (int i = 0; i < 5; i++) {
		printf("Value of index %d is %d.\n", i, find(node, i));
	}
	printf("\n");

	node = delete(node, 4);
	printf("Value of index 4 was deleted: ");
	printList(node);

	node = delete(node, 2);
	printf("Value of index 2 was deleted: ");
	printList(node);

	node = delete(node, 0);
	printf("Value of index 0 was deleted: ");
	printList(node);
	printf("\n");

	return 0;
}