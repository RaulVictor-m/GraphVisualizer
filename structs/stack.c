#include "mem.h"
#include "stack.h"
#include "array_list.h"

struct Stack {
    ArrayList data;
};

Stack st_init(size_t elem_size) {
    Stack st = alloc(sizeof(struct Stack));
    st->data = al_init(0, elem_size);
    return st;
}

void st_clear(Stack st) {
    al_clear(st->data);
    dealloc(st);
}

size_t st_size(Stack st) {
    return al_size(st->data);
}

void st_push(Stack st, void *new_data) {
    al_push_back(st->data, new_data);
}

void st_pop(Stack st) {
    al_pop_back(st->data);
}

void* st_top(Stack st) {
    return al_back(st->data);
}
