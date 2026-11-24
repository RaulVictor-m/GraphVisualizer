#include "linked_list.h"
#include "mem.h"

// struct Node {
//     void* data;
//     Node* next;
//     Node* prev;
// };

// typedef struct Node Node;

// struct LinkedList {
//     Node* head;
//     Node* tail;
//     size_t size, elem_sz;
// };

// void ll_init(size_t elem_size) {
//     LinkedList ls = alloc(sizeof(struct LinkedList));

//     ls->head = ls->tail = 0;
//     ls->elem_sz = elem_size;
//     ls->size = 0;

//     return ls;
// }

// void ll_push_back(LinkedList ls, void* new_data) {
//     node = alloc(sizeof(struct Node));
//     copy(node->data, new_data, ls->elem_sz);

//     if (ls->size == 0) {
//         node->next = node->prev = 0;
//         ls->head = node;
//         ls->tail = node;
//         return;
//     } 

//     ls->tail->next = node;
//     node->next = 0;
//     node->prev = ls->tail;
//     ls->tail = node;
// }

// void ll_push_front(LinkedList ls, void* new_data) {
//     node = alloc(sizeof(struct Node));
//     copy(node->data, new_data, ls->elem_sz);

//     if (ls->size == 0) {
//         node->next = node->prev = 0;
//         ls->head = node;
//         ls->tail = node;
//         return;
//     } 

//     ls->head->prev = node;
//     node->next = ls->head;
//     node->prev = 0;
//     ls->head = node;
// }

// void ll_size(LinkedList ls) {
//     return ls->size;
// }

