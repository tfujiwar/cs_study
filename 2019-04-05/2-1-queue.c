#include <stdio.h>
#include <stdlib.h>

typedef struct LIST_NODE{
	int value;
	struct LIST_NODE *next;
} list_node;

typedef struct {
	list_node *head;
} list_queue_t;

void printQueue(list_queue_t *queue)
{
	list_node *node = queue->head;
	printf("[ ");
	while (node != NULL) {
		printf("%d ", node->value);
		node = node->next;
	}
	printf("]\n");
}

void enqueue(list_queue_t *queue, int value)
{
	list_node *new_node;
	new_node = (list_node*) malloc(sizeof(list_node));

	new_node->value = value;
	new_node->next = queue->head;
	queue->head = new_node;
}

int dequeue(list_queue_t *queue)
{
	int value;
	list_node *deleted_node;
	list_node *node = queue->head;

	if (node->next == NULL) {
		deleted_node = node;
		queue->head = NULL;
	} else {
		while (node->next->next != NULL) {
			node = node->next;
		}
		deleted_node = node->next;
		node->next = NULL;
	}

	value = deleted_node->value;
	free(deleted_node);
	return value;
}

int main()
{
	list_queue_t *queue;

	for (int i = 0; i < 5; i++) {
		enqueue(queue, i);
		printf("Value %d was added: ", i);
		printQueue(queue);
	}
	printf("\n");

	for (int i = 0; i < 5; i++) {
		printf("Value %d was removed: ", dequeue(queue));
		printQueue(queue);
	}
	printf("\n");

	return 0;
}