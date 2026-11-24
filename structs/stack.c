#include "mem.h"
#include "stack.h"
#include "array_list.h"

struct Stack {
    ArrayList data;
};

Stack st_init_r(size_t elem_size) {
    Stack st = alloc(sizeof(struct Stack));
    st->data = al_init_r(0, elem_size);
    return st;
}

void st_clear_r(Stack st) {
    al_clear_r(st->data);
    dealloc(st);
}

size_t st_size_r(Stack st) {
    return al_size_r(st->data);
}

void st_push_r(Stack st, void *new_data) {
    al_push_back_r(st->data, new_data);
}

void st_pop_r(Stack st) {
    al_pop_back_r(st->data);
}

void* st_top_r(Stack st) {
    return al_back_r(st->data);
}
