#ifndef array_list_h_INCLUDED
#define array_list_h_INCLUDED

#include <stdint.h>
#include <stddef.h>

typedef struct ArrayList* ArrayList;

ArrayList al_init_r(size_t n, size_t elem_size);
void al_clear_r(ArrayList vs);

size_t al_size_r(ArrayList vs);

void al_push_back_r(ArrayList vs, void *new_data);
void al_pop_back_r(ArrayList vs);

void* al_at_r(ArrayList vs, size_t i);
void* al_back_r(ArrayList vs);
void* al_front_r(ArrayList vs);

#ifndef TYPE_OF
#define TYPE_OF __typeof__
#endif

#define ArrayListOf(T)  T*

#define al_init(n, T)   ((T*)al_init_r((n), sizeof(T)))
#define al_clear(vs)    al_clear_r((ArrayList)(vs))

#define al_size(vs)     al_size_r((ArrayList)(vs))

#define al_push_back(vs, ...) \
    al_push_back_r((ArrayList)(vs), &(TYPE_OF(*(vs))){__VA_ARGS__})

#define al_pop_back(vs) al_pop_back_r((ArrayList)(vs))

#define al_at(vs, i)    ((TYPE_OF(*(vs))*)al_at_r((ArrayList)(vs), (i)))
#define al_back(vs)     ((TYPE_OF(*(vs))*)al_back_r((ArrayList)(vs)))
#define al_front(vs)    ((TYPE_OF(*(vs))*)al_front_r((ArrayList)(vs)))

#endif // arraylist_h_INCLUDED
