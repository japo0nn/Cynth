#include <headers.h>
#include <list.h>

int main(void) {
	printf("%s", "Hello Cynth!\n");
    List(int) list;
    list_init(&list);

    int a = 30;
    list_append(&list, &a);
    for (int i = 0; i < list.size; i++) {
        printf("%d\n", list.data[i]); // Прямой доступ через массив
    }
    printf("%d \n", list.data[0]);
    list_free(&list);
	return 0;
}
