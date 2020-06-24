#include <stdlib.h>
#include <stdio.h>
#include "queue.h"

void new_queue(Queue* queue) {
	queue->first = NULL;
	queue->last = queue->first;
	queue->size = 0;
}

void enqueue(Queue* queue, Item item) {
	NodePtr new_node;
	new_node = (NodePtr) malloc(sizeof(Node));
	new_node->item = item;
	new_node->next = NULL;
	if (queue->size == 0) {
		queue->first = new_node;
		queue->last = new_node;
	} else {
		queue->last-> next = new_node;
		queue->last = new_node;
	}
	queue->size++;
}

int dequeue(Queue* queue, Item* item) {
	if (queue->size < 1) return 0;	// underflow

	NodePtr deleted_node;
	deleted_node = queue->first;
	queue->first = deleted_node->next;
	*item = deleted_node->item;
	free(deleted_node);
	queue->size--;
	return 1;
}

void delete_queue(Queue* queue) {
	Item aux;
	int removed;
	do {
		removed = dequeue(queue, &aux);
	} while (removed);
}
