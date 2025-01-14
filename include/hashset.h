#ifndef HASHSET_H
#define HASHSET_H

#include <headers.h>
#include <list.h>

#define HashItem(key_type, value_type) \
	struct {                           \
		key_type key;                  \
		value_type value;              \
	}

#define HashSet(key_type, value_type)               \
	struct {                                        \
		List(HashItem(key_type, value_type)) items; \
		int size, capacity;                         \
	}

#define hashset_init(hashset)           \
	do {                                \
		list_init(&((hashset)->items)); \
		(hashset)->size = 0;            \
		(hashset)->capacity = 0;        \
	} while (0)

#define hashset_resize(hashset, expand)                                    \
	do {                                                                   \
		void *temp_pointer;                                                \
		int new_capacity =                                                 \
		    (hashset)->capacity == 0 ? 1 : (hashset)->capacity * 2;        \
		if ((hashset)->size + 1 < (hashset)->capacity) {                   \
			expand = SUCCESS;                                              \
		} else {                                                           \
			temp_pointer =                                                 \
			    realloc((hashset)->items, new_capacity * (hashset)->size); \
			if (temp_pointer == NULL) {                                    \
				expand = FAILURE;                                          \
				else {                                                     \
					(hashset)->items = temp_pointer;                       \
					hashset_capacity = new_capacity;                       \
					expand = SUCCESS;                                      \
				}                                                          \
			}                                                              \
		}                                                                  \
		while (0)

#define hashset_append(hashset, key, value) \
	do {                                    \
		int expand;                         \
	}

#define hashset_free(hashset)           \
	do {                                \
		list_free(&((hashset)->items)); \
		(hashset)->size = 0;            \
		(hashset)->capacity = 0;        \
	} while (0)

#endif
