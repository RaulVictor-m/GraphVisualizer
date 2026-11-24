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

#ifndef TYPE_OF
#define TYPE_OF __typeof__
#endif

#define LinkedListOf(T)  T*
#define ll_init_t(T)    ((T*)ll_init(sizeof(T)))
#define ll_clear_t(ls)  ll_clear((LinkedList)(ls))

#define ll_size_t(ls)   ll_size((LinkedList*)(ls))

#define ll_head_t(ls)   ((TYPE_OF(*(ls))*)ll_head((LinkedList)(ls)))
#define ll_tail_t(ls)   ((TYPE_OF(*(ls))*)ll_tail((LinkedList)(ls)))
#define ll_end_t(ls)    ((TYPE_OF(*(ls))*)ll_end((LinkedList)(ls)))

#define ll_at_t(it)     ((TYPE_OF(*(it))*)ll_at((void*)(it)))
#define ll_next_t(it)   ((TYPE_OF(*(it))*)ll_next((void*)(it)))
#define ll_prev_t(it)   ((TYPE_OF(*(it))*)ll_prev((void*)(it)))

#define ll_insert_after_t(ls, it, ...) \
    ll_insert_after((LinkedList)(ls), (void*)(it), &(TYPE_OF(*(ls))){__VA_ARGS__})

#define ll_insert_before_t(ls, it, ...) \
    ll_insert_before((LinkedList)(ls), (void*)(it), &(TYPE_OF(*(ls))){__VA_ARGS__})

#define ll_push_back_t(ls, ...) \
    ll_push_back((LinkedList)(ls), &(TYPE_OF(*(ls))){__VA_ARGS__})

#define ll_push_front_t(ls, ...) \
    ll_push_front((LinkedList)(ls), &(TYPE_OF(*(ls))){__VA_ARGS__})

#define ll_del_at_t(ls, it)   ll_del_at((LinkedList)(ls), (void*)(it))

#define ll_pop_back_t(ls)     ll_pop_back((LinkedList)(ls))
#define ll_pop_front_t(ls)    ll_pop_front((LinkedList)(ls))

#endif // linked_list_h_INCLUDED
