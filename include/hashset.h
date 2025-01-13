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
    }while(0)

#define hashset_free(hashset)               \
    do {                                    \
        list_free(&((hashset)->items));     \
        (hashset)->size = 0;                \
        (hashset)->capacity = 0;            \
    }while(0)

#endif
