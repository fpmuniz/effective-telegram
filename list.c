#include <stdio.h>
#include <stdlib.h>
#include "list.h"

void init_item(Item* item) {
	item->next = NULL;
	item->prev = NULL;
	item->key = 0;
}

Item* new_item() {
	Item *item;
	item = (Item*) malloc(sizeof(Item));
	init_item(item);
	return item;
}

void print_item(const Item *item) {
	printf("%d\n", item->key);
}

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
	new->prev = previous;
	new->next = previous->next;
	*new = *to_insert;
	previous->next->prev = new;
	previous->next = new;
	list->size++;
}

void delete(List* list, Item* item) {
	item->prev->next = item->next;
	item->next->prev = item->prev;
	free(item);
	list->size--;
}

void wipe_list(List* list) {
	Item* aux;
	while (list->size > 0) {
		aux = list->head->next;
		delete(list, aux);
	}
}

void delete_list(List* list) {
	wipe_list(list);
	free(list->head);
	free(list);
}

void print_list(const List* list) {
	Item *aux = list->head->next;
	while (aux != list->head) {
		print_item(aux);
		aux = aux->next;
	}
}