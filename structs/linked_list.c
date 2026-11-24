#include "linked_list.h"
#include "mem.h"
#include <assert.h>

typedef struct Node Node;
struct Node {
    void* data;
    Node* next;
    Node* prev;
};

struct LinkedList {
    Node sent;
    size_t size, elem_sz;
};

// private
Node* _new_node(void* elem, size_t elem_sz) {
    Node* node = alloc(sizeof(struct Node));
    node->data = alloc(elem_sz);

    node->prev = node->next = 0;
    if (elem != 0)
        copy(node->data, elem, elem_sz);

    return node;
}

void _del_node(Node* node) {
    dealloc(node->data);
    dealloc(node);
}

// public

LinkedList ll_init(size_t elem_size) {
    LinkedList ls = alloc(sizeof(struct LinkedList));
    ls->sent.next = ls->sent.prev = &ls->sent;

    ls->elem_sz = elem_size;
    ls->size = 0;

    return ls;
}

void ll_clear(LinkedList ls) {
    while (ls->size > 0) ll_pop_back(ls);
    dealloc(ls);
}

size_t ll_size(LinkedList ls) { return ls->size; }

void* ll_begin(LinkedList ls) {
    return ls->sent.next;
}

void* ll_end(LinkedList ls) {
    return ls->sent.prev;
}

void* ll_next(void* it) {
    return ((Node*)it)->next;
}

void* ll_prev(void* it) {
    return ((Node*)it)->prev;
}

void* ll_at(void* it) {
    return ((Node*)it)->data; //TODO: check not empty
}

void ll_insert_after(LinkedList ls, void* it, void* new_data) {
    Node* node = _new_node(new_data, ls->elem_sz);

    node->next = ((Node*)it)->next;
    node->prev = it;

    node->next->prev = node;
    node->prev->next = node;
    ls->size++;
}

void ll_insert_before(LinkedList ls, void* it, void* new_data) {
    Node* node = _new_node(new_data, ls->elem_sz);

    node->prev = ((Node*)it)->prev;
    node->next = it;

    node->next->prev = node;
    node->prev->next = node;
    ls->size++;
}

void ll_push_back(LinkedList ls, void* new_data) {
    ll_insert_after(ls, &ls->sent, new_data);
}

void ll_push_front(LinkedList ls, void* new_data) {
    ll_insert_before(ls, &ls->sent, new_data);
}

void ll_del_at(LinkedList ls, void* it) {
    if (it == (&ls->sent)) {
        //TODO: error
        return;
    }
    ((Node*)it)->prev->next = ((Node*)it)->next;
    ((Node*)it)->next->prev = ((Node*)it)->prev;
    _del_node(it);
    ls->size--;
}

void ll_pop_back(LinkedList ls) {
    ll_del_at(ls, ls->sent.prev);
}

void ll_pop_front(LinkedList ls) {
    ll_del_at(ls, ls->sent.next);
}


