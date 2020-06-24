#include <stdio.h>
#include <stdlib.h>
#include "list.h"

void new_list(List *list) {
	list->head = (NodePtr) malloc(sizeof(Node));
	list->head->next = list->head;
	list->head->prev = list->head;
	list->size = 0;
}

Node* search(const List *list, KeyType key) {
	Node *aux = list->head->next;
	while (aux != list->head) {
		if (aux->item.key == key)
			return aux;
		aux = aux->next;
	}
	return NULL;
}

Node* insert(List* list, Node* node, Item item) {
	Node *new_node = (Node*) malloc(sizeof(Node));
	new_node->prev = node;
	new_node->next = node->next;
	new_node->item = item;
	node->next->prev = node;
	node->next = new_node;
	list->size++;
	return new_node;
}

Node* append(List* list, Item item) {
	// insertion at the end
	Node *new_node = (Node*) malloc(sizeof(Node));
	new_node->next = list->head;
	new_node->prev = list->head->prev;
	list->head->prev->next = new_node;
	list->head->prev = new_node;
	new_node->item = item;
	list->size++;
	return new_node;
}

void delete(List* list, Node* node) {
	node->prev->next = node->next;
	node->next->prev = node->prev;
	free(node);
	list->size--;
}

void delete_list(List* list) {
	Node* aux = NULL;
	while (list->size > 0) {
		aux = list->head->next;
		delete(list, aux);
	}
	free(list->head);
}
