#include <assert.h>
#include "stack.h"

void test_create_new_stack() {
	Stack *stack;
	stack = new_stack();
	delete_stack(stack);
}

void test_push_and_pop() {
	Stack *stack = new_stack();
	Item item;
	init_item(&item);
	for (int i = 0; i < 10; i++) {
		item.key = i;
		push(stack, &item);
	}
	for (int i = 9; i > -1; i--) {
		assert(pop(stack, &item));
		assert(item.key == i);
	}
	delete_stack(stack);
}

void test_print_stack() {
	Stack *stack = new_stack();
	Item item;
	init_item(&item);
	for (int i = 0; i < 10; i++) {
		item.key = i;
		push(stack, &item);
	}
	print_stack(stack);
	delete_stack(stack);
}

void test_stack_size() {
	Stack *stack = new_stack();
	Item item;
	init_item(&item);
	for (int i = 0; i < 10; i++) {
		assert(stack->size == i);
		item.key = i;
		push(stack, &item);
		assert(stack->size == i + 1);
	}
	delete_stack(stack);
}

int main() {
	test_create_new_stack();
	test_push_and_pop();
	test_print_stack();
	test_stack_size();
}
