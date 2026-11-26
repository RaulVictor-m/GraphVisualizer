#ifndef stack_h_INCLUDED
#define stack_h_INCLUDED

typedef struct Stack* Stack;

Stack st_init_r(size_t elem_size);

size_t st_size_r(Stack st);
void st_push_r(Stack st, void *new_data);
void st_pop_r(Stack st);
void* st_top_r(Stack st);
void st_clear_r(Stack st);

#include "phantom.h"

#define ST_CHK(vs) \
    PH_CHK(vs, __ST_TAG, "Expected StackOf(T)")

#define ST_T(x)          PH_ELEM(x)
#define ST_CAST(st)      ((Stack)(st))
#define StackOf(T)       PH_TYPE(T, __ST_TAG)

#define st_init(T)       ((StackOf(T))st_init_r(sizeof(T)))
#define st_size(st)      (ST_CHK(st), st_size_r(ST_CAST(st)))

#define st_push(st, ...) (\
    ST_CHK(st), \
    st_push_r(ST_CAST(st), &(ST_T(st)){__VA_ARGS__}))

#define st_pop(st)       (ST_CHK(st), st_pop_r(ST_CAST(st)))

#define st_top(st)       (ST_CHK(st), (ST_T(st)*)st_top_r(ST_CAST(st)))

#define st_clear(st)     (ST_CHK(st), st_clear_r(ST_CAST(st)))

#endif // stack_h_INCLUDED
