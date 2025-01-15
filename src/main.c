#include <hashset.h>
#include <headers.h>
#include <list.h>
#include <sha256.h>

int main(void) {
	printf("%s", "Hello Cynth!\n");
	List(int) list;
	list_init(&list);

	unsigned long long a = 30;
	list_append(&list, &a);
	for (int i = 0; i < list.size; i++) {
		printf("%d\n", list.data[i]);  // Прямой доступ через массив
	}
	printf("%d \n", list.data[0]);
	list_free(&list);

	HashSet(int, int) hs;
	hashset_init(&hs);

	char *str1 = "sss";
	char *str2 = "sss";

	bool isEquals = string_equals(str1, str2);
	printf("%d\n", isEquals);
	hashset_free(&hs);
	bool isEqual = false;
	printf("%d\n", isEqual);

	int value = 12345;
	uint8_t hash[32];

	sha256_hash(&value, sizeof(value), hash);

	printf("Hash of int value:\n");
	for (int i = 0; i < 32; i++) {
		printf("%d", hash[i]);
	}
	printf("\n");

    if (memcmp(hash, hash, 32) == 0)
        printf("Success\n");
    else{
        printf("Failure\n");
    }
	return 0;
}
