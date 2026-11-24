#include <stdio.h>
#include <assert.h>

#include "stack.h"
#include "array_list.h"
#include "linked_list.h"

void test_raw_stack(int n) {
    Stack st = st_init(4); // int stack

    for (int i = 1; i <= n; i++) 
        st_push(st, &(int){i*i});

    for (int i = n; i > 0; i--) {
        assert(*(int*)st_top(st) == i*i);
        assert(st_size(st) == i);

        st_pop(st);
        assert(st_size(st) == i-1);
    }

    st_clear(st);
}

void test_typed_stack(int n) {
    StackOf(int) st = st_init_t(int); // int stack

    for (int i = 1; i <= n; i++) 
        st_push_t(st, i*i);

    for (int i = n; i > 0; i--) {
        assert(*st_top_t(st) == i*i);
        assert(st_size_t(st) == i);

        st_pop_t(st);
        assert(st_size_t(st) == i-1);
    }

    st_clear_t(st);
}

void test_raw_array_list(int n) {
    ArrayList vs = al_init(n, 4);

    for (int i = 1; i <= n; i++) 
        *(int*)al_at(vs, i-1) = i*i;

    for (int i = n; i > 0; i--) {
        assert(*(int*)al_at(vs, i-1) == i*i);
        assert(al_size(vs) == i);

        al_pop_back(vs);
        assert(al_size(vs) == i-1);
    }

    al_clear(vs);
}

void test_typed_array_list(int n) {
    ArrayListOf(int) vs = al_init_t(n, int);

    for (int i = 1; i <= n; i++) 
        *al_at_t(vs, i-1) = i*i;

    for (int i = n; i > 0; i--) {
        assert(*al_at_t(vs, i-1) == i*i);
        assert(al_size_t(vs) == i);

        al_pop_back_t(vs);
        assert(al_size_t(vs) == i-1);
    }

    al_clear_t(vs);
}

void test_raw_linked_list(int n) {
    LinkedList ls = ll_init(4); //list of int

    for (int i = 1; i <= n; i++) ll_push_back(ls, &(int){i*i});
        // if (i%2 == 1) ll_push_back(ls, &(int){i*i});
        // else          ll_push_front(ls, &(int){i*i});

    int i = 1;
    for (auto it = ll_head(ls); it != ll_end(ls); it = ll_next(it)) {
        assert(*(int*)ll_at(it) == i*i);
        i++;
    }

    ll_clear(ls);
}

int main(void) {
    int n = 50000;
    printf("raw stack: \n");
    test_raw_stack(n);
    printf("passed\n\n");

    printf("typed stack: \n");
    test_typed_stack(n);
    printf("passed\n\n");

    printf("raw array list: \n");
    test_raw_array_list(n);
    printf("passed\n\n");

    printf("typed array list: \n");
    test_typed_array_list(n);
    printf("passed\n\n");

    printf("raw linked list: \n");
    test_raw_linked_list(20);
    printf("passed\n\n");

    //TODO: make better tests
    return 0;
}
