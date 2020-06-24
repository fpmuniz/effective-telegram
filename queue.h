#pragma once
#include "slcell.h"

typedef struct Queue Queue;

struct Queue {
	Item *first, *last;
	int size;
};

void init_queue(Queue*);

Queue* new_queue();

void enqueue(Queue*, const Item*);

int dequeue(Queue*, Item*);

void wipe_queue(Queue*);

void delete_queue(Queue*);

void print_queue(const Queue*);
