#ifndef TOKEN_TYPES_H
#define TOKEN_TYPES_H

#define TOKEN_TYPE_COUNT 2

#include <headers.h>
#include <stdio.h>

enum TokenTypes {
	RETURN,
	SEMICOL,
};

typedef struct {
	enum TokenTypes tokenType;
	const char* ch;
} Token;

typedef struct {
	Token tokens[TOKEN_TYPE_COUNT];
	size_t size;
} TokenMap;

void token_map_init(TokenMap* map);
int token_hash(char* key);
void token_map_append(TokenMap* map, char* key, enum TokenTypes token_type);
void token_map_free(TokenMap* map);

#endif
