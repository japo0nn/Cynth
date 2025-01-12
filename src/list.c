#include <list.h>
#include <safefree.h>
#include <stdlib.h>
#include <string.h>

void list_init(List *list, size_t element_size) {
	list->data = NULL;
	list->size = 0;
	list->capacity = 0;
	list->element_size = element_size;
}

void list_resize(List *list, size_t new_capacity) {
	list->data = realloc(list->data, new_capacity * list->element_size);
	if (new_capacity > list->capacity) {
		memset((char *)list->data + list->capacity * list->element_size, 0,
		       (new_capacity - list->capacity) * list->element_size);
	}
	list->capacity = new_capacity;
}

void list_append(List *list, void *element) {
	if (list->size == list->capacity) {
		size_t new_capacity = list->capacity == 0 ? 1 : list->capacity * 2;
		list_resize(list, new_capacity);
	}
	memcpy((char *)list->data + list->element_size, element,
	       list->element_size);
	list->size++;
}

void list_free(List *list) {
	SAFE_FREE(list->data);
	list->data = NULL;
	list->capacity = 0;
	list->size = 0;
}
