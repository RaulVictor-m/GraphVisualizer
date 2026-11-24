#ifndef stack_h_INCLUDED
#define stack_h_INCLUDED

typedef struct Stack* Stack;

Stack st_init(size_t elem_size);

size_t st_size(Stack st);
void st_push(Stack st, void *new_data);
void st_pop(Stack st);
void* st_top(Stack st);
void st_clear(Stack st);

#ifndef TYPE_OF
#define TYPE_OF __typeof__
#endif

#define StackOf(T)         T*
#define st_init_t(T)       ((T*)st_init(sizeof(T)))
#define st_size_t(st)      st_size((Stack)(st))

#define st_push_t(st, ...) st_push((Stack)(st), &(TYPE_OF(*(st))){__VA_ARGS__})
#define st_pop_t(st)       st_pop((Stack)(st))

#define st_top_t(st)       ((TYPE_OF(*(st))*)st_top((Stack)(st)))

#define st_clear_t(st)     st_clear((Stack)(st))

#endif // stack_h_INCLUDED
