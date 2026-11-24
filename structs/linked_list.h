#ifndef linked_list_h_INCLUDED
#define linked_list_h_INCLUDED

typedef struct LinkedList* LinkedList;

#include <stdint.h>
#include <stddef.h>

LinkedList ll_init_r(size_t elem_size);
void ll_clear_r(LinkedList ls);

size_t ll_size_r(LinkedList ls);

void* ll_head_r(LinkedList ls);
void* ll_tail_r(LinkedList ls);
void* ll_end_r(LinkedList ls); // returns the sentinal marking the end of the iteration

void* ll_next_r(void* it);
void* ll_prev_r(void* it);

void* ll_at_r(void* it); // unwraps an iterator

void ll_insert_after_r(LinkedList ls, void* it, void* new_data);
void ll_insert_before_r(LinkedList ls, void* it, void* new_data);

void ll_push_back_r(LinkedList ls, void* new_data);
void ll_push_front_r(LinkedList ls, void* new_data);

void ll_del_at_r(LinkedList ls, void* it);

void ll_pop_back_r(LinkedList ls);
void ll_pop_front_r(LinkedList ls);

#ifndef TYPE_OF
#define TYPE_OF __typeof__
#endif

#define LinkedListOf(T)  T*
#define ll_init(T)    ((T*)ll_init_r(sizeof(T)))
#define ll_clear(ls)  ll_clear_r((LinkedList)(ls))

#define ll_size(ls)   ll_size((LinkedList*)(ls))

#define ll_head(ls)   ((TYPE_OF(*(ls))*)ll_head_r((LinkedList)(ls)))
#define ll_tail(ls)   ((TYPE_OF(*(ls))*)ll_tail_r((LinkedList)(ls)))
#define ll_end(ls)    ((TYPE_OF(*(ls))*)ll_end_r((LinkedList)(ls)))

#define ll_at(it)     ((TYPE_OF(*(it))*)ll_at_r((void*)(it)))
#define ll_next(it)   ((TYPE_OF(*(it))*)ll_next_r((void*)(it)))
#define ll_prev(it)   ((TYPE_OF(*(it))*)ll_prev_r((void*)(it)))

#define ll_insert_after(ls, it, ...) \
    ll_insert_after_r((LinkedList)(ls), (void*)(it), &(TYPE_OF(*(ls))){__VA_ARGS__})

#define ll_insert_before(ls, it, ...) \
    ll_insert_before_r((LinkedList)(ls), (void*)(it), &(TYPE_OF(*(ls))){__VA_ARGS__})

#define ll_push_back(ls, ...) \
    ll_push_back_r((LinkedList)(ls), &(TYPE_OF(*(ls))){__VA_ARGS__})

#define ll_push_front(ls, ...) \
    ll_push_front_r((LinkedList)(ls), &(TYPE_OF(*(ls))){__VA_ARGS__})

#define ll_del_at(ls, it)   ll_del_at_r((LinkedList)(ls), (void*)(it))

#define ll_pop_back(ls)     ll_pop_back_r((LinkedList)(ls))
#define ll_pop_front(ls)    ll_pop_front_r((LinkedList)(ls))

#endif // linked_list_h_INCLUDED
