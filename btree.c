#include <stdlib.h>
#include <stdio.h>
#include "btree.h"

Tree* new_tree() {
	Tree* tree;
	tree = (Tree*) malloc(sizeof(Tree));
	init_tree(tree);
	return tree;
}

void init_tree(Tree* tree) {
	tree->root = NULL;
}

Item* root(Item* item) {
	while (item->parent != NULL)
		item = item->parent;
	return item;
}

Item* search(Item* item, KeyType key) {
	while (item != NULL && key != item->key) {
		if (key < item->key)
			item = item->left;
		else
			item = item->right;
	}
	return item;
}

Item* min(Item* item) {
	if (item == NULL) return NULL;
	while (item->left != NULL) {
		item = item->left;
	}
	return item;
}

Item* max(Item* item) {
	while (item->right != NULL) {
		item = item->right;
	}
	return item;
}

Item* successor(Item* item) {
	Item* parent;
	if (item->right != NULL) 
		return min(item->right);
	parent = item->parent;
	while (parent != NULL && item == parent->right) {
		item = parent;
		parent = item->parent;
	}
	return parent;
}

Item* predecessor(Item* item) {
	Item* parent;
	if (item->left != NULL) 
		return max(item->left);
	parent = item->parent;
	while (parent != NULL && item == parent->left) {
		item = parent;
		parent = item->parent;
	}
	return parent;
}

Item* insert(Tree* tree, const Item* item) {
	Item *y = NULL, *x = tree->root;
	while (x != NULL) {
		y = x;
		if (item->key < x->key)
			x = x->left;
		else
			x = x->right;
	}
	if (y == NULL) {
		x = new_item();
		*x = *item;
		tree->root = x;	// tree was empty
		return x;
	}

	x = new_item();
	x->parent = y;
	*x = *item;
	if (item->key < y->key) {
		y->left = x;
	} else {
		y-> right = x;
	}
	return x;
}

void recursive_delete(Item* item) {
	if (item == NULL) return;
	recursive_delete(item->left);
	recursive_delete(item->right);
	free(item);
}

void wipe_tree(Tree* tree) {
	recursive_delete(tree->root);
}

void delete_tree(Tree* tree) {
	wipe_tree(tree);
	free(tree);
}

void print_inorder(const Item* item) {
	if (item == NULL) return;
	print_inorder(item->left);
	print_item(item);
	print_inorder(item->right);
}

void print_preorder(const Item* item) {
	if (item == NULL) return;
	print_item(item);
	print_preorder(item->left);
	print_preorder(item->right);	
}

void print_postorder(const Item* item) {
	if (item == NULL) return;
	print_postorder(item->left);
	print_postorder(item->right);	
	print_item(item);
}
