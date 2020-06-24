#include <assert.h>
#include "queue.h"

void test_create_new_queue() {
	Queue *queue;
	queue = new_queue();
	delete_queue(queue);
}

void test_enqueue_and_dequeue() {
	Queue *queue = new_queue();
	Item item;
	init_item(&item);
	for (int i = 0; i < 10; i++) {
		item.key = i;
		enqueue(queue, &item);
	}
	for (int i = 0; i < 10; i++) {
		assert(dequeue(queue, &item));
		assert(item.key == i);
	}
	delete_queue(queue);
}

void test_print_queue() {
	Queue *queue = new_queue();
	Item item;
	init_item(&item);
	for (int i = 0; i < 10; i++) {
		item.key = i;
		enqueue(queue, &item);
	}
	print_queue(queue);
	delete_queue(queue);
}

void test_queue_size() {
	Queue *queue = new_queue();
	Item item;
	init_item(&item);
	for (int i = 0; i < 10; i++) {
		assert(queue->size == i);
		item.key = i;
		enqueue(queue, &item);
		assert(queue->size == i + 1);
	}
	delete_queue(queue);
}

int main() {
	test_create_new_queue();
	test_enqueue_and_dequeue();
	test_print_queue();
	test_queue_size();
}
