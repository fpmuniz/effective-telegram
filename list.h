#pragma once

#include "dlcell.h"

typedef struct List List;

struct List {
	Item *head;
	int size;
};

void init_list(List*);

List* new_list();

void append(List*, const Item*);

void insert(List*, Item*, const Item*);

void delete(List*, Item*);

Item* search(const List*, KeyType);

void wipe_list(List*);

void delete_list(List*);

void print_list(const List*);
