#include <stdio.h>
#include <stdlib.h>

typedef struct LIST_NODE{
	int value;
	struct LIST_NODE *next;
} list_node;

typedef struct {
	list_node *head;
} list_stack_t;

void printStack(list_stack_t *stack)
{
	list_node *node = stack->head;
	printf("[ ");
	while (node != NULL) {
		printf("%d ", node->value);
		node = node->next;
	}
	printf("]\n");
}

void push(list_stack_t *stack, int value)
{
	list_node *new_node;
	new_node = (list_node*) malloc(sizeof(list_node));

	new_node->value = value;
	new_node->next = stack->head;
	stack->head = new_node;
}

int pop(list_stack_t *stack)
{
	list_node *old_head;
	int value;

	old_head = stack->head;
	value = old_head->value;
	stack->head = old_head->next;

	free(old_head);
	return value;
}

int main()
{
	list_stack_t *stack;

	for (int i = 0; i < 5; i++) {
		push(stack, i);
		printf("Value %d was added: ", i);
		printStack(stack);
	}
	printf("\n");

	for (int i = 0; i < 5; i++) {
		printf("Value %d was removed: ", pop(stack));
		printStack(stack);
	}
	printf("\n");

	return 0;
}