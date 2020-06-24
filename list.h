#pragma once

typedef struct NodeStr* NodePtr;
typedef struct NodeStr Node;
typedef struct ListStr List;
typedef struct ItemStr Item;
typedef int KeyType;

struct ItemStr {
	KeyType key;
	/* --- Other fields --- */
};

struct NodeStr {
	NodePtr next, prev;
	Item item;
};

struct ListStr {
	NodePtr head;
	int size;
};

void new_list(List*);

Node* search(const List*, KeyType);

Node* insert(List*, Node*, Item);

void delete(List*, Node*);

void delete_list(List*);
