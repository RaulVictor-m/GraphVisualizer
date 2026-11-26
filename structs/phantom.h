#ifndef phantom_h_INCLUDED
#define phantom_h_INCLUDED

#include <stddef.h>
#include <assert.h>

#ifndef TYPE_OF
#define TYPE_OF __typeof__
#endif

enum {
    __LL_TAG = 0xDEAD,
    __LL_IT_TAG,
    __AL_TAG,
    __ST_TAG,
};

#define PH_TYPE(T, TAG)    TYPE_OF(TYPE_OF(T) *(*)[TAG])
#define PH_ELEM(x)         TYPE_OF(***(x)) 

// MAGIC
#define PH_ASSERT(cond, m) ((void)sizeof(struct { _Static_assert((cond), m); char _; }))
#define PH_CHK(x, TAG, m)  PH_ASSERT((sizeof(*(x)) == (size_t)(TAG) * sizeof(**(x))), m)

#endif // phantom_h_INCLUDED
