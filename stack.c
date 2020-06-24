#include <stdlib.h>
#include <stdio.h>
#include "stack.h"

void init_item(Item* item) {
	// set default values for item
	item->key = 0;
	item->next = NULL;
}

Item* new_item() {
	// allocate memory for a new item and initialize it
	Item* item;
	item = (Item*) malloc(sizeof(Item));
	init_item(item);
	return item;
}

void print_item(const Item* item) {
	printf("%d\n", item->key);
}

void delete_item(Item* item) {
	free(item);
}

void init_stack(Stack* stack) {
	stack->top = NULL;
	stack->size = 0;
}

Stack* new_stack() {
	// allocate memory and initialize a stack
	Stack *stack;
	stack = (Stack*) malloc(sizeof(Stack));
	init_stack(stack);
	return stack;
}

void push(Stack* stack, const Item* item) {
	Item *new = new_item();
	*new = *item;
	new->next = stack->top;
	stack->top = new;
	stack->size++;
}

int pop(Stack* stack, Item* item) {
	if (stack->size == 0) {
		return 0; // underflow
	}

	Item* del;
	del = stack->top;
	stack->top = del->next;
	if (item != NULL) *item = *del;
	delete_item(del);
	stack->size--;
	return 1;
}

void wipe_stack(Stack* stack) {
	int popped;
	do {
		popped = pop(stack, NULL);
	} while (popped);
}

void delete_stack(Stack* stack) {
	wipe_stack(stack);
	free(stack);
}

void print_stack(const Stack* stack) {
	Item *item = stack->top;
	while (item != NULL) {
		print_item(item);
		item = item->next;
	}
}
