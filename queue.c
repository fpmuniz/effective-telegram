#include <stdlib.h>
#include <stdio.h>
#include "queue.h"

void init_queue(Queue* queue) {
	queue->first = NULL;
	queue->last = queue->first;
	queue->size = 0;
}

Queue* new_queue() {
	Queue *queue;
	queue = (Queue*) malloc(sizeof(Queue));
	init_queue(queue);
	return queue;
}

void enqueue(Queue* queue, const Item* item) {
	Item *new;
	new = new_item();
	*new = *item;
	new->next = NULL;
	if (queue->size == 0)
		queue->first = new;
	else
		queue->last->next = new;
	queue->last = new;
	queue->size++;
}

int dequeue(Queue* queue, Item* item) {
	if (queue->size < 1) return 0;	// underflow

	Item* del;
	del = queue->first;
	queue->first = del->next;
	if (item != NULL) *item = *del;
	free(del);
	queue->size--;
	return 1;
}

void wipe_queue(Queue* queue) {
	int removed;
	do {
		removed = dequeue(queue, NULL);
	} while (removed);
}

void delete_queue(Queue* queue) {
	wipe_queue(queue);
	free(queue);
}

void print_queue(const Queue* queue) {
	Item *item = queue->first;
	while (item != NULL) {
		print_item(item);
		item = item->next;
	}
}
