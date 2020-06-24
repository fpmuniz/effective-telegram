#include <assert.h>
#include "list.h"

void test_create_new_list() {
	List *list;
	list = new_list();
	delete_list(list);
}

void test_append_and_delete() {
	List *list = new_list();
	Item item, *aux;
	init_item(&item);
	for (int i = 0; i < 10; i++) {
		item.key = i;
		append(list, &item);
	}
	for (int i = 0; i < 10; i++) {
		aux = list->head->next;
		delete(list, aux);
	}
	delete_list(list);
}

void test_print_list() {
	List *list = new_list();
	Item item;
	init_item(&item);
	for (int i = 0; i < 10; i++) {
		item.key = i;
		append(list, &item);
	}
	print_list(list);
	delete_list(list);
}

void test_list_size() {
	List *list = new_list();
	Item item;
	init_item(&item);
	for (int i = 0; i < 10; i++) {
		assert(list->size == i);
		item.key = i;
		append(list, &item);
		assert(list->size == i + 1);
	}
	delete_list(list);
}

int main() {
	test_create_new_list();
	test_append_and_delete();
	test_print_list();
	test_list_size();
}
