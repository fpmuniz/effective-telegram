#pragma once

typedef struct Item Item;
typedef int KeyType;

struct Item {
	Item *left, *right, *parent;
	KeyType key;
	/* --- Other fields --- */
};

void init_item(Item*);

Item* new_item();

void print_item(const Item*);

void delete_item(Item*);
