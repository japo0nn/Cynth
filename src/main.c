#include <headers.h>
#include <list.h>
#include <sha256.h>
#include <stdint.h>
#include <hash_operations.h>
#include <map.h>

int main(int argc, char *argv[]) {
    if (argc < 2)
        printf("Please specify filepath\nExit code -2\n");
    else
        printf("Debugging started\n");

    char alph[] = "abcdefghiljklmnopqrstuvwxyz";
    uint32_t hashed = hash_data(alph, sizeof(alph));
    printf("Hash: %u\n", hashed);

    Map(char*, int) mapper;
    map_init(&mapper);
    uint32_t hash;
    char* key1 = "abc";
    char* key2 = "map";
    char* key3 = "333";
    int a = 3;
    int b = 5;
    int c = 7;
    map_insert(&mapper, key1, &a);  // Вставляем значение
    int* result;
    get_by_hash(&mapper, key1, result);  // Получаем значение по ключу

    if (result) {
        printf("Value: %d\n", *result);  // Выводим значение
    } else {
        printf("Value not found\n");
    }

    map_insert(&mapper, key2, &b);  // Вставляем значение
    map_insert(&mapper, key3, &c);

    List(char **) list1;
    List(int *) list2;

    list_init(&list1);
    list_init(&list2);
    get_by_hash(&mapper, key2, result);  // Получаем значение по ключу

    if (result) {
        printf("Value: %d\n", *result);  // Выводим значение
    } else {
        printf("Value not found\n");
    }


    get_by_hash(&mapper, key3, result);  // Получаем значение по ключу

    if (result) {
        printf("Value: %d\n", *result);  // Выводим значение
    } else {
        printf("Value not found\n");
    }
	return 0;
}
