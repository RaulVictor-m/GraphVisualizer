#ifndef array_list_h_INCLUDED
#define array_list_h_INCLUDED

#include <stdint.h>
#include <stddef.h>

typedef struct ArrayList* ArrayList;

ArrayList al_init(size_t n, size_t elem_size);
void al_clear(ArrayList vs);

size_t al_size(ArrayList vs);

void al_push_back(ArrayList vs, void *new_data);
void al_pop_back(ArrayList vs);

void* al_at(ArrayList vs, size_t i);
void* al_back(ArrayList vs);
void* al_front(ArrayList vs);

#ifndef TYPE_OF
#define TYPE_OF __typeof__
#endif

#define ArrayListOf(T)  T*

#define al_init_t(n, T)   ((T*)al_init((n), sizeof(T)))
#define al_clear_t(vs)    al_clear((ArrayList)(vs))

#define al_size_t(vs)     al_size((ArrayList)(vs))

#define al_push_back_t(vs, ...) \
    al_push_back((ArrayList)(vs), &(TYPE_OF(*(vs))){__VA_ARGS__})

#define al_pop_back_t(vs) al_pop_back((ArrayList)(vs))

#define al_at_t(vs, i)    ((TYPE_OF(*(vs))*)al_at((ArrayList)(vs), (i)))
#define al_back_t(vs)     ((TYPE_OF(*(vs))*)al_back((ArrayList)(vs)))
#define al_front_t(vs)    ((TYPE_OF(*(vs))*)al_front((ArrayList)(vs)))

#endif // arraylist_h_INCLUDED
