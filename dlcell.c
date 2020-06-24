#include <stdlib.h>
#include <stdio.h>
#include "dlcell.h"

void init_item(Item* item) {
	item->next = NULL;
	item->prev = NULL;
	item->key = 0;
}

Item* new_item() {
	Item *item;
	item = (Item*) malloc(sizeof(Item));
	init_item(item);
	return item;
}

void print_item(const Item *item) {
	printf("%d\n", item->key);
}

void delete_item(Item* item) {
	free(item);
}

