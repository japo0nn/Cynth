#include <compiler.h>

void compiler_init(TokenMap* map) {
	token_map_init(map);
	token_map_append(map, "return", RETURN);
	token_map_append(map, ";", SEMICOL);
	token_map_free(map);
}
