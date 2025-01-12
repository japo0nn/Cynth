#ifndef HASHSET_H
#define HASHSET_H

#define HashItem(key_type, value_type) \
	struct {                           \
		key_type key;                  \
		value_type value;              \
	}

#define HashSet(key_type, value_type)           \
	struct {                                    \
		HashItem(key_type, value_type) items[]; \
		size_t size, capacity;                  \
		int count;                              \
	}

#endif
