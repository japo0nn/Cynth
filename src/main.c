#include <list.h>
#include <stdio.h>

int main(void) {
	printf("%s", "Hello Cynth!\n");
	List list;
	list_init(&list, sizeof(int));

	int a = 10, b = 20, c = 30;
	list_append(&list, &a);

	for (int i = 0; i < list.size; i++) {
		printf("%d\n", *(int *)((char *)list.data + i * list.element_size));
	}

	printf("%zu\n", list.size);
	return 0;
}
