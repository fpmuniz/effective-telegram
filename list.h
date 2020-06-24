#pragma once

typedef struct Item Item;
typedef struct List List;
typedef int KeyType;

struct Item {
	Item *next, *prev;
	KeyType key;
	/* --- Other fields --- */
};

struct List {
	Item *head;
	int size;
};

void init_item(Item* item);

Item* new_item();

void print_item(const Item *item);

void init_list(List*);

List* new_list();

void append(List*, const Item*);

void insert(List*, Item*, const Item*);

void delete(List*, Item*);

Item* search(const List*, KeyType);

void wipe_list(List*);

void delete_list(List*);

void print_list(const List*);
