#pragma once

#include "slcell.h"

typedef struct Stack Stack;

struct Stack {
	Item* top;
	int size;
};

// Initializes a stack with default values
void init_stack(Stack*);

// Allocates memory for a stack and initializes its values
Stack* new_stack();

// Inserts a COPY of an item into a stack
void push(Stack*, const Item*);

/* Removes item on top of a stack, copies its contents into 2nd parameter,
frees memory from item on stack, and returns 1 if successful or 0 if not (stack 
empty). You can pass NULL for 2nd argument if you don't need a copy of the 
removed item, to speed things up.
*/
int pop(Stack*, Item*);

/* Empties a stack, removing all of its items. This does not deallocate memory,
i.e., does not call free() on the stack pointer. */
void wipe_stack(Stack*);

// Empties a stack and frees the memory used by it.
void delete_stack(Stack*);

// Prints a stack by calling print_item for each item in the stack.
void print_stack(const Stack*);
