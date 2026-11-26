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

#include "phantom.h"

#define LL_CHK(ls) \
    PH_CHK(ls, __LL_TAG, "Expected LinkedListOf(T)")

#define LL_CHK_IT(it) \
    PH_CHK(it, __LL_IT_TAG, "Expected LinkedListIt(T)")

#define LL_T(x)          PH_ELEM(x)
#define LL_CAST(ls)      ((LinkedList)(ls))
#define LinkedListOf(T)  PH_TYPE(T, __LL_TAG)
#define LinkedListIt(T)  PH_TYPE(T, __LL_IT_TAG)

#define ll_init(T)   ((LinkedListOf(T))ll_init_r(sizeof(T)))
#define ll_clear(ls) (LL_CHK(ls), ll_clear_r(LL_CAST(ls)))

#define ll_size(ls)  (LL_CHK(ls), ll_size_r(LL_CAST(ls)))

#define ll_head(ls)  (LL_CHK(ls), (LinkedListIt(LL_T(ls)))ll_head_r(LL_CAST(ls)))
#define ll_tail(ls)  (LL_CHK(ls), (LinkedListIt(LL_T(ls)))ll_tail_r(LL_CAST(ls)))
#define ll_end(ls)   (LL_CHK(ls), (LinkedListIt(LL_T(ls)))ll_end_r(LL_CAST(ls)))

#define ll_at(it)    (LL_CHK_IT(it), (LL_T(it)*)ll_at_r((void*)(it)))
#define ll_next(it)  (LL_CHK_IT(it), (LinkedListIt(LL_T(it)))ll_next_r((void*)(it)))
#define ll_prev(it)  (LL_CHK_IT(it), (LinkedListIt(LL_T(it)))ll_prev_r((void*)(it)))

#define ll_insert_after(ls, it, ...) (\
    LL_CHK(ls), LL_CHK_IT(it), \
    ll_insert_after_r(LL_CAST(ls), (void*)(it), &(LL_T(ls)){__VA_ARGS__}))

#define ll_insert_before(ls, it, ...) (\
    LL_CHK(ls), LL_CHK_IT(it), \
    ll_insert_before_r(LL_CAST(ls), (void*)(it), &(LL_T(ls)){__VA_ARGS__}))

#define ll_push_back(ls, ...) (\
    LL_CHK(ls), \
    ll_push_back_r(LL_CAST(ls), &(LL_T(ls)){__VA_ARGS__}))

#define ll_push_front(ls, ...) (\
    LL_CHK(ls), \
    ll_push_front_r(LL_CAST(ls), &(LL_T(ls)){__VA_ARGS__}))

#define ll_del_at(ls, it) (\
    LL_CHK(ls), LL_CHK_IT(it), \
    ll_del_at_r(LL_CAST(ls), (void*)(it)))

#define ll_pop_back(ls) (\
    LL_CHK(ls), \
    ll_pop_back_r(LL_CAST(ls)))

#define ll_pop_front(ls) (\
    LL_CHK(ls), \
    ll_pop_back_r(LL_CAST(ls)))

#endif // linked_list_h_INCLUDED
