#include <stdio.h>
#include <stdlib.h>
#include "list.h"

List* new_list() {
	List *list = (List*) malloc(sizeof(List));
	list->head = new_item();
	init_list(list);
	return list;
}

void init_list(List* list) {
	list->head->next = list->head;
	list->head->prev = list->head;
	list->size = 0;
}

Item* search(const List *list, KeyType key) {
	Item *aux = list->head->next;
	while (aux != list->head) {
		if (aux->key == key)
			return aux;
		aux = aux->next;
	}
	return NULL;
}

void append(List* list, const Item *item) {
	// insertion at the end
	Item *new = new_item();
	*new = *item;
	new->next = list->head;
	new->prev = list->head->prev;
	list->head->prev->next = new;
	list->head->prev = new;
	list->size++;
}

void insert(List* list, Item* previous, const Item* to_insert) {
	Item *new = new_item();
	*new = *to_insert;
	new->prev = previous;
	new->next = previous->next;
	previous->next->prev = new;
	previous->next = new;
	list->size++;
}

void delete(List* list, Item* item) {
	item->prev->next = item->next;
	item->next->prev = item->prev;
	delete_item(item);
	list->size--;
}

void wipe_list(List* list) {
	while (list->size > 0) {
		delete(list, list->head->next);
	}
}

void delete_list(List* list) {
	wipe_list(list);
	delete_item(list->head);
	free(list);
}

void print_list(const List* list) {
	Item *aux = list->head->next;
	while (aux != list->head) {
		print_item(aux);
		aux = aux->next;
	}
}