#include <assert.h>
#include "btree.h"

Tree* create_base_tree() {
	Tree *tree = new_tree();
	Item item;
	init_item(&item);
	item.key = 10;
	insert(tree, &item);
	item.key = 5;
	insert(tree, &item);
	item.key = 15;
	insert(tree, &item);
	item.key = 7;
	insert(tree, &item);
	item.key = 3;
	insert(tree, &item);
	item.key = 12;
	insert(tree, &item);
	item.key = 20;
	insert(tree, &item);
	item.key = 42;
	insert(tree, &item);
	return tree;
}
void test_create_delete_tree() {
	Tree *tree;
	tree = new_tree();
	delete_tree(tree);
}

void test_insert() {
	Tree *tree = create_base_tree();
	delete_tree(tree);
}

void test_search() {
	Tree *tree = create_base_tree();
	Item *aux;
	aux = search(tree->root, 0);
	assert(!aux);	// not found, nullptr
	aux = search(tree->root, 15);
	assert(aux->key == 15);
	delete_tree(tree);
}

void test_predecessor() {
	Tree *tree = create_base_tree();
	Item *aux;
	aux = search(tree->root, 15);
	aux = predecessor(aux);
	assert(aux->key == 12);
	delete_tree(tree);
}

void test_successor() {
	Tree *tree = create_base_tree();
	Item *aux;
	aux = search(tree->root, 15);
	aux = successor(aux);
	assert(aux->key == 20);
	delete_tree(tree);
}

void test_max() {
	Tree *tree = create_base_tree();
	Item *aux;
	aux = max(tree->root);
	assert(aux->key == 42);
	delete_tree(tree);
}

void test_min() {
	Tree *tree = create_base_tree();
	Item *aux;
	aux = min(tree->root);
	assert(aux->key == 3);
	delete_tree(tree);
}

void test_print() {
	Tree *tree = create_base_tree();
	print_inorder(tree->root);
	print_preorder(tree->root);
	print_postorder(tree->root);
}

int main() {
	test_create_delete_tree();
	test_insert();
	test_search();
	test_predecessor();
	test_successor();
	test_max();
	test_min();
	test_print();
}
