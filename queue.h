#pragma once

typedef struct NodeStr* NodePtr;
typedef struct NodeStr Node;
typedef struct QueueStr Queue;
typedef struct ItemStr Item;
typedef int KeyType;

struct ItemStr {
	KeyType key;
	/* --- Other fields --- */
};

struct NodeStr {
	NodePtr next;
	Item item;
};

struct QueueStr {
	NodePtr first;
	NodePtr last;
	int size;
};

void new_queue(Queue*);

void enqueue(Queue*, Item);

int dequeue(Queue*, Item*);

void delete_queue(Queue*);
