#include <stdio.h>
#define QUEUE_SIZE 10

typedef struct {
	int values[QUEUE_SIZE];
	int count;
} queue_t;

void printQueue(queue_t *queue)
{
	printf("[ ");
	for (int i = 0; i < queue->count; i++) {
		printf("%d ", queue->values[i]);
	}
	printf("]\n");
}

void enqueue(queue_t *queue, int value)
{
	if (queue->count < QUEUE_SIZE) {
		queue->values[queue->count] = value;
		queue->count++;
	}
}

int dequeue(queue_t *queue)
{
	if (queue->count > 0) {
		int value = queue->values[0];
		for (int i = 0; i < queue->count - 1; i++) {
			queue->values[i] = queue->values[i + 1];
		}
		queue->count--;
		return value;
	}
}

int main()
{
	queue_t queue;
	queue.count = 0;

	for (int i = 0; i < 5; i++) {
		enqueue(&queue, i);
		printf("Value %d was added: ", i);
		printQueue(&queue);
	}
	printf("\n");

	for (int i = 0; i < 5; i++) {
		printf("Value %d was removed: ", dequeue(&queue));
		printQueue(&queue);
	}
	printf("\n");

	return 0;
}