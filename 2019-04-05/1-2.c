#include <stdio.h>
#define QUEUE_SIZE 10

typedef struct {
	int values[QUEUE_SIZE];
	int count;
} queue_t;

void printQueue(queue_t *queue)
{
	for (int i = 0; i < queue->count; i++) {
		printf("%d ", queue->values[i]);
	}
	printf("\n");
}

void enqueue(queue_t *queue, int value)
{
	if (queue->count < QUEUE_SIZE) {
		queue->values[queue->count] = value;
		queue->count++;
		printQueue(queue);
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
		printQueue(queue);
		return value;
	}
}

int main()
{
	queue_t queue;
	queue.count = 0;

	enqueue(&queue, 1);
	enqueue(&queue, 2);
	enqueue(&queue, 3);
	enqueue(&queue, 4);
	enqueue(&queue, 5);

	dequeue(&queue);
	dequeue(&queue);
	dequeue(&queue);
	dequeue(&queue);
	dequeue(&queue);

	return 0;
}