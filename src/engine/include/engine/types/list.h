#ifndef ENGINE_TYPES_LIST_H
#define ENGINE_TYPES_LIST_H

#include <stddef.h>

typedef struct List {
    size_t data_size;
    size_t size;
    size_t count;
    char *data;
} List;

List list_new(size_t data_size, size_t reserve);
void list_destroy(List *list);
void list_erase(List *list, void *element);
void list_push_back(List *list, void *element);

#endif // ENGINE_TYPES_LIST_H
