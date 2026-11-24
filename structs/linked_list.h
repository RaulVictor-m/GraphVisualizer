#ifndef linked_list_h_INCLUDED
#define linked_list_h_INCLUDED

typedef struct LinkedList* LinkedList;

#include <stdint.h>
#include <stddef.h>

LinkedList ll_init(size_t elem_size);
void ll_clear(LinkedList ls);

size_t ll_size(LinkedList ls);

void* ll_head(LinkedList ls);
void* ll_tail(LinkedList ls);
void* ll_end(LinkedList ls); // returns the sentinal marking the end of the iteration

void* ll_next(void* it);
void* ll_prev(void* it);

void* ll_at(void* it); // unwraps an iterator

void ll_insert_after(LinkedList ls, void* it, void* new_data);
void ll_insert_before(LinkedList ls, void* it, void* new_data);

void ll_push_back(LinkedList ls, void* new_data);
void ll_push_front(LinkedList ls, void* new_data);

void ll_del_at(LinkedList ls, void* it);

void ll_pop_back(LinkedList ls);
void ll_pop_front(LinkedList ls);


#endif // linked_list_h_INCLUDED
