#pragma once

typedef struct NodeStr BTree;
typedef struct ItemStr Item;
typedef int KeyType;

struct ItemStr {
	KeyType key;
	/* --- Other fields --- */
};

struct NodeStr {
	BTree *left, *right, *parent;
	Item item;
};

BTree* new_tree();

BTree* search(BTree*, KeyType);

BTree* min(BTree*);

BTree* max(BTree*);

BTree* predecessor(BTree*);

BTree* successor(BTree*);

BTree* root(BTree*);

BTree* insert(BTree*, Item);

void delete(BTree*, BTree*);

void delete_tree(BTree*);
