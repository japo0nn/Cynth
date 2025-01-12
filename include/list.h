#ifndef LIST_H
#define LIST_H

#include <stdlib.h>

typedef struct {
	void *data;
	size_t capacity, size, element_size;
} List;

void list_init(List *list, size_t element_size);
void list_resize(List *list, size_t new_capacity);
void list_append(List *list, void *element);
void list_free(List *list);

#endif
