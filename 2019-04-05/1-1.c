#include <stdio.h>
#define STACK_SIZE 10

typedef struct {
	int values[STACK_SIZE];
	int count;
} stack_t;

void printStack(stack_t *stack)
{
	printf("[ ");
	for (int i = 0; i < stack->count; i++) {
		printf("%d ", stack->values[i]);
	}
	printf("]\n");
}

void push(stack_t *stack, int value)
{
	if (stack->count < STACK_SIZE) {
		stack->values[stack->count] = value;
		stack->count++;
	}
}

int pop(stack_t *stack)
{
	if (stack->count > 0) {
		int value = stack->values[stack->count - 1];
		stack->count--;
		return value;
	}
}

int main()
{
	stack_t stack;
	stack.count = 0;

	for (int i = 0; i < 5; i++) {
		push(&stack, i);
		printf("Value %d was added: ", i);
		printStack(&stack);
	}
	printf("\n");

	for (int i = 0; i < 5; i++) {
		printf("Value %d was removed: ", pop(&stack));
		printStack(&stack);
	}
	printf("\n");

	return 0;
}