#pragma once

typedef struct Stack Stack;
typedef struct Item Item;
typedef int KeyType;

struct Item {
	Item* next;
	KeyType key;
	/* --- Other fields --- */
};

struct Stack {
	Item* top;
	int size;
};

// Initializes an Item with default values
void init_item(Item*);

// Allocates memory for an Item and initializes it
Item* new_item();

// Prints Item to stdout
void print_item(const Item*);

// Frees memory dynamically allocated to an item
void delete_item(Item*);

// Initializes a stack with default values
void init_stack(Stack*);

// Allocates memory for a stack
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
