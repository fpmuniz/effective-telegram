#include <stdlib.h>
#include <stdio.h>
#include "btree.h"

BTree* new_tree() {
	BTree *tree = (BTree*) malloc(sizeof(BTree));
	tree->left = NULL;
	tree->right = NULL;
	tree->parent = NULL;
	return tree;
}

BTree* root(BTree* tree) {
	while (tree->parent != NULL)
		tree = tree->parent;
	return tree;
}

BTree* search(BTree* tree, KeyType key) {
	tree = root(tree);
	while (tree != NULL && key != tree->item.key) {
		if (key < tree->item.key)
			tree = tree->left;
		else
			tree = tree->right;
	}
	return tree;
}

BTree* min(BTree* tree) {
	while (tree->left != NULL) {
		tree = tree->left;
	}
	return tree;
}

BTree* max(BTree* tree) {
	while (tree->right != NULL) {
		tree = tree->right;
	}
	return tree;
}

BTree* successor(BTree* tree) {
	BTree* parent;
	if (tree->right != NULL) 
		return min(tree->right);
	parent = tree->parent;
	while (parent != NULL && tree == parent->right) {
		tree = parent;
		parent = tree->parent;
	}
	return parent;
}

BTree* predecessor(BTree* tree) {
	BTree* parent;
	if (tree->left != NULL) 
		return max(tree->left);
	parent = tree->parent;
	while (parent != NULL && tree == parent->left) {
		tree = parent;
		parent = tree->parent;
	}
	return parent;
}

BTree* insert(BTree* tree, Item item) {
	BTree *y = NULL, *x = root(tree);
	while (x != NULL) {
		y = x;
		if (item.key < x->item.key)
			x = x->left;
		x = x->right;
	}
	if (y == NULL) {
		tree->item = item;	// tree was empty
		return tree;
	}

	x = new_tree();
	x->parent = y;
	x->item = item;
	if (item.key < y->item.key) {
		y->left = x;
	} else {
		y-> right = x;
	}
	return x;
}

void delete_tree(BTree* tree) {
	if (tree->left) delete_tree(tree->left);
	if (tree->right) delete_tree(tree->right);
	free(tree);
}

void print_inorder(BTree* tree) {
	if (tree == NULL) return;
	print_inorder(tree->left);
	printf("%d\n", tree->item.key);
	print_inorder(tree->right);
}

// int main() {
// 	BTree *tree, *aux;
// 	Item item;
// 	tree = new_tree();
// 	item.key = 10;
// 	aux = insert(tree, item);
// 	item.key = 11;
// 	aux = insert(tree, item);
// 	item.key = 12;
// 	aux = insert(tree, item);
// 	print_inorder(root(tree));
// 	delete_tree(tree);
// 	return 0;
// }
