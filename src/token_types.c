#include <token_types.h>

void token_map_init(TokenMap* map) { map->size = TOKEN_TYPE_COUNT; }

int token_hash(char* key) {
	int hash = 5381;
	int c;

	while ((c = *key++)) {
		hash = ((hash << 5) + hash) + c;  // hash * 33 + c
	}

	return hash % TOKEN_TYPE_COUNT;
}

void token_map_append(TokenMap* map, char* key, enum TokenTypes token_type) {
	int hash = token_hash(key);
	map->tokens[hash].tokenType = token_type;
	map->tokens[hash].ch = key;
}
