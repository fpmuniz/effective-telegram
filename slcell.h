#pragma once

typedef int KeyType;
typedef struct Item Item;

struct Item {
	Item *next;
	KeyType key;
	/* --- Other fields --- */
};

void init_item(Item*);

Item* new_item();

void print_item(const Item*);

void delete_item(Item*);
