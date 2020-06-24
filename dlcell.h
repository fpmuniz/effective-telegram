#pragma once

typedef int KeyType;
typedef struct Item Item;

struct Item {
	Item *next, *prev;
	KeyType key;
	/* --- Other fields --- */
};


void init_item(Item* item);

Item* new_item();

void print_item(const Item *item);

void delete_item(Item* item);
