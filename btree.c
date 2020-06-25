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
	Item *parent = NULL, *new = tree->root;
	while (new != NULL) {
		parent = new;
		if (item->key < new->key)
			new = new->left;
		else
			new = new->right;
	}
	new = new_item();
	if (parent == NULL) {
		*new = *item;
		tree->root = new;	// tree was empty
		return new;
	}

	*new = *item;
	new->parent = parent;
	if (item->key < parent->key) {
		parent->left = new;
	} else {
		parent-> right = new;
	}
	return new;
}

void transplant(Tree* tree, Item* old, Item* new) {
	if (old->parent == NULL) {
		tree->root = new;
	}
	else if (old == old->parent->left) {
		old->parent->left = new;
	} else {
		old->parent->right = new;
	}
	if (new) new->parent = old->parent;
}

void delete(Tree* tree, Item* old) {
	Item *new;
	if (old->left == NULL) {
		transplant(tree, old, old->right);
	}
	else if (old->right == NULL) {
		transplant(tree, old, old->left);
	}
	else {
		new = successor(old);
		if (new->parent != old) {
			transplant(tree, new, new->right);
			new->right = old->right;
			new->right->parent = new;
		}
		transplant(tree, old, new);
		new->left = old->left;
		new->left->parent = new;
	}
	delete_item(old);
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
