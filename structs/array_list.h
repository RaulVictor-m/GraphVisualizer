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

#include "phantom.h"

#define AL_CHK(vs) \
    PH_CHK(vs, __AL_TAG, "Expected ArrayListOf(T)")

#define AL_T(x)          PH_ELEM(x)
#define AL_CAST(vs)      ((ArrayList)(vs))
#define ArrayListOf(T)   PH_TYPE(T, __AL_TAG)

#define al_init(n, T)   ((ArrayListOf(T))al_init_r((n), sizeof(T)))
#define al_clear(vs)    (AL_CHK(vs), al_clear_r(AL_CAST(vs)))

#define al_size(vs)     (AL_CHK(vs), al_size_r(AL_CAST(vs)))

#define al_push_back(vs, ...) (\
    AL_CHK(vs), \
    al_push_back_r(AL_CAST(vs), &(AL_T(vs)){__VA_ARGS__}))

#define al_pop_back(vs) (AL_CHK(vs), al_pop_back_r(AL_CAST(vs)))

#define al_at(vs, i)    (AL_CHK(vs), (AL_T(vs)*)al_at_r(AL_CAST(vs), (i)))
#define al_back(vs)     (AL_CHK(vs), (ArrayList(AL_T(vs)))al_back_r(AL_CAST(vs)))
#define al_front(vs)    (AL_CHK(vs), (ArrayList(AL_T(vs)))al_front_r(AL_CAST(vs)))

#endif // arraylist_h_INCLUDED
