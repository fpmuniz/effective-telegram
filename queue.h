#pragma once

typedef struct Queue Queue;
typedef struct Item Item;
typedef int KeyType;

struct Item {
	Item *next;
	KeyType key;
	/* --- Other fields --- */
};

struct Queue {
	Item *first, *last;
	int size;
};

void init_item(Item*);

Item* new_item();

void print_item(const Item*);

void delete_item(Item*);

void init_queue(Queue*);

Queue* new_queue();

void enqueue(Queue*, const Item*);

int dequeue(Queue*, Item*);

void wipe_queue(Queue*);

void delete_queue(Queue*);

void print_queue(const Queue*);
