#ifndef stack_h_INCLUDED
#define stack_h_INCLUDED

typedef struct Stack* Stack;

Stack st_init_r(size_t elem_size);

size_t st_size_r(Stack st);
void st_push_r(Stack st, void *new_data);
void st_pop_r(Stack st);
void* st_top_r(Stack st);
void st_clear_r(Stack st);

#ifndef TYPE_OF
#define TYPE_OF __typeof__
#endif

#define StackOf(T)         T*
#define st_init(T)       ((T*)st_init_r(sizeof(T)))
#define st_size(st)      st_size_r((Stack)(st))

#define st_push(st, ...) st_push_r((Stack)(st), &(TYPE_OF(*(st))){__VA_ARGS__})
#define st_pop(st)       st_pop_r((Stack)(st))

#define st_top(st)       ((TYPE_OF(*(st))*)st_top_r((Stack)(st)))

#define st_clear(st)     st_clear_r((Stack)(st))

#endif // stack_h_INCLUDED
