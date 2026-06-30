#include <engine/types/list.h>

#include <stdlib.h>


List list_new(size_t data_size, size_t reserve) {
    List list = {
        .data_size = data_size,
        .size = reserve,
        .count = 0,
        .data = calloc(reserve, data_size)
    };

    if (!list.data) {
        abort();
    }

    return list;
}


void list_destroy(List *list) {
    if (!list || !list->data) {
        return;
    }

    free(list->data);
    memset(list, 0, sizeof(List));
}


void list_erase(List *list, void *element) {
    if (!list || !list->data || !element) {
        return;
    }


    size_t element_to_erase = SIZE_MAX;

    for (size_t i = 0; i < list->count; i++) {
        if (memcmp(list->data + i * list->data_size, element, list->data_size) == 0) {
            element_to_erase = i;
            break;
        }
    }


    if (element_to_erase == SIZE_MAX) {
        return;
    }

    memset(list->data + element_to_erase * list->data_size, 0, list->data_size);

    for (size_t i = element_to_erase + 1; i < list->count; i++) {
        memmove(list->data + (i - 1) * list->data_size,
                list->data + i * list->data_size, list->data_size);
    }

    list->count--;
}


void list_push_back(List *list, void *element) {
    if (!list || !list->data || !element) {
        return;
    }


    if (list->size > list->count) {
        memcpy(list->data + (list->data_size * list->count++), element, list->data_size);
    } else {
        list->size += 4;
        list->data = realloc(list->data, list->size * list->data_size);

        if (!list->data) {
            abort();
        }

        memcpy(list->data + (list->data_size * list->count++), element, list->data_size);
    }
}
