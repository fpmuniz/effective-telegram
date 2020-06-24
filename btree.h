#pragma once

#include "bnode.h"


typedef struct Tree Tree;

struct Tree {
	Item* root;
};

Tree* new_tree();

void init_tree(Tree*);

Item* root(Item*);

Item* search(Item*, KeyType);

Item* min(Item*);

Item* max(Item*);

Item* predecessor(Item*);

Item* successor(Item*);

Item* insert(Tree*, const Item*);

void delete(Tree*, Tree*);

void print_inorder(const Item*);

void print_preorder(const Item*);

void print_postorder(const Item*);

void wipe_tree(Tree*);

void delete_tree(Tree*);
