#include <compiler.h>
#include <stdio.h>
#include <token_types.h>

int main(int argc, char *argv[]) {
	TokenMap token_map;
	compiler_init(&token_map);
	for (size_t i = 0; i < token_map.size; i++) {
		if (token_map.tokens[i].ch != NULL)
			printf("Token[%ld] = %s\n", i, token_map.tokens[i].ch);
	}
	return 0;
}
