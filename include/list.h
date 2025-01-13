#ifndef LIST_H
#define LIST_H

#include <headers.h>

#define List(datatype)               \
	struct {                         \
		datatype *data;              \
		unsigned long long size;     \
		unsigned long long capacity; \
		size_t data_size;            \
	}

#define list_init(list)                              \
	do {                                             \
		(list)->data = NULL;                         \
		(list)->size = 0;                            \
		(list)->capacity = 0;                        \
		(list)->data_size = sizeof(*((list)->data)); \
	} while (0)

#define list_resize(list, expand)                                            \
	do {                                                                     \
		void *temp_pointer;                                                  \
		int new_capacity = (list)->capacity == 0 ? 1 : (list)->capacity * 2; \
                                                                             \
		if ((list)->size + 1 < (list)->capacity) {                           \
			expand = SUCCESS;                                                \
		} else {                                                             \
			temp_pointer =                                                   \
			    realloc((list)->data, new_capacity * (list)->data_size);     \
                                                                             \
			if (temp_pointer == NULL) {                                      \
				expand = FAILURE;                                            \
			} else {                                                         \
				(list)->data = temp_pointer;                                 \
				(list)->capacity = new_capacity;                             \
				expand = SUCCESS;                                            \
			}                                                                \
		}                                                                    \
	} while (0)

#define list_append(list, element)                          \
	do {                                                    \
		int expand;                                         \
		list_resize(list, expand);                          \
		if (expand == SUCCESS) {                            \
			(list)->data[(list)->size] = *(element);        \
			(list)->size++;                                 \
		} else                                              \
			printf("Could not expand. Push back failed\n"); \
	} while (0)

#define list_free(list)          \
	do {                         \
		SAFE_FREE((list)->data); \
		(list)->data = NULL;     \
		(list)->size = 0;        \
		(list)->capacity = 0;    \
	} while (0)

#endif
