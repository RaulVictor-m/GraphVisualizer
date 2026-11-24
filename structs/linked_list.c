#include "linked_list.h"
#include "mem.h"

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

LinkedList ll_init_r(size_t elem_size) {
    LinkedList ls = alloc(sizeof(struct LinkedList));
    ls->sent.next = ls->sent.prev = &ls->sent;

    ls->elem_sz = elem_size;
    ls->size = 0;

    return ls;
}

void ll_clear_r(LinkedList ls) {
    while (ls->size > 0) ll_pop_back_r(ls);
    dealloc(ls);
}

size_t ll_size_r(LinkedList ls) { return ls->size; }

void* ll_head_r(LinkedList ls) {
    return ls->sent.next;
}

void* ll_tail_r(LinkedList ls) {
    return ls->sent.prev;
}

void* ll_end_r(LinkedList ls) {
    return &ls->sent;
}

void* ll_next_r(void* it) {
    return ((Node*)it)->next;
}

void* ll_prev_r(void* it) {
    return ((Node*)it)->prev;
}

void* ll_at_r(void* it) {
    return ((Node*)it)->data; //TODO: check not empty
}

void ll_insert_after_r(LinkedList ls, void* it, void* new_data) {
    Node* node = _new_node(new_data, ls->elem_sz);

    node->next = ((Node*)it)->next;
    node->prev = it;

    node->next->prev = node;
    node->prev->next = node;
    ls->size++;
}

void ll_insert_before_r(LinkedList ls, void* it, void* new_data) {
    Node* node = _new_node(new_data, ls->elem_sz);

    node->prev = ((Node*)it)->prev;
    node->next = it;

    node->next->prev = node;
    node->prev->next = node;
    ls->size++;
}

void ll_push_back_r(LinkedList ls, void* new_data) {
    ll_insert_before_r(ls, &ls->sent, new_data);
}

void ll_push_front_r(LinkedList ls, void* new_data) {
    ll_insert_after_r(ls, &ls->sent, new_data);
}

void ll_del_at_r(LinkedList ls, void* it) {
    if (it == (&ls->sent)) {
        //TODO: error
        return;
    }
    ((Node*)it)->prev->next = ((Node*)it)->next;
    ((Node*)it)->next->prev = ((Node*)it)->prev;
    _del_node(it);
    ls->size--;
}

void ll_pop_back_r(LinkedList ls) {
    ll_del_at_r(ls, ls->sent.prev);
}

void ll_pop_front_r(LinkedList ls) {
    ll_del_at_r(ls, ls->sent.next);
}


