#ifndef MAP_H
#define MAP_H

#include <hash_operations.h>
#include <headers.h>
#include <list.h>
#include <stdint.h>

#define Map(key_type, value_type)  \
	struct {                       \
		List(key_type *) keys;     \
		List(value_type *) values; \
		size_t size;               \
	}

#define map_init(map)                \
	do {                             \
		list_init(&((map)->keys));   \
		list_init(&((map)->values)); \
		(map)->size = 1;             \
	} while (0)

#define map_hash(map, key, hash, size)              \
	do {                                            \
		printf("map_hash: HASH SIZE: %zu\n", size); \
		hash = hash_data(key, sizeof(*key));        \
		printf("map_hashh: Hash: %u\n", hash);      \
		hash %= size + 1;                           \
	} while (0)

#define get_by_hash(map, key, value)                   \
	do {                                               \
		printf("get_by_hash: KEY: %s\n", key);         \
		uint32_t hash;                                 \
		map_hash(map, key, hash, ((map)->size));       \
		if (hash < ((map)->values).capacity - 1) {     \
			printf("get_by_hash: ValCapacity: %llu\n", \
			       ((map)->values).capacity + 1);      \
			printf("get_by_hash: Hash: %d\n", hash);   \
			value = (((map)->values).data[hash]);      \
		} else {                                       \
			value = NULL;                              \
		}                                              \
	} while (0)

#define map_insert(map, key, value)                                           \
	do {                                                                      \
		void *existing_value;                                                 \
		get_by_hash(map, key, existing_value);                                \
		printf("%p\n", existing_value);                                       \
		if (existing_value == NULL) {                                         \
			printf("Зашел\n");                                                \
			int expand;                                                       \
			list_resize(&((map)->values), expand);                            \
			list_resize(&((map)->keys), expand);                              \
			((map)->keys).size++;                                             \
			((map)->values).size++;                                           \
			(map)->size++;                                                    \
			if (expand == SUCCESS) {                                          \
				for (int i = 0; i < ((map)->values).capacity &&               \
				                ((map)->values).capacity > 2;                 \
				     i++) {                                                   \
					uint32_t new_hash;                                        \
					printf("Здесь\n");                                        \
					printf("Key[%d]: %s\n", i, *(((map)->keys).data[i]));     \
					map_hash(map, ((map)->keys).data[i], new_hash,            \
					         (map)->size);                                    \
					printf("Here - 2: New_hash: %u\n", new_hash);             \
					(((map)->values).data[new_hash]) =                        \
					    (((map)->values).data[i]);                            \
					(((map)->keys).data[new_hash]) = (((map)->keys).data[i]); \
					(((map)->values).data[i]) = NULL;                         \
					(((map)->keys).data[i]) = NULL;                           \
				}                                                             \
			} else {                                                          \
				printf("Expand failure\n");                                   \
			}                                                                 \
			uint32_t hash;                                                    \
			map_hash(map, key, hash, (map)->size);                            \
			(((map)->values).data[hash]) = value;                             \
			(((map)->keys).data[hash]) = &key;                                \
		}                                                                     \
	} while (0)

#define map_free(map) \
	do {              \
	}

#endif
