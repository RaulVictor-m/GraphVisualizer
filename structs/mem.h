#ifndef mem_h_INCLUDED
#define mem_h_INCLUDED

#include <stdlib.h>
#include <string.h>

// standalone
#include <stddef.h>
#include <stdint.h>

// this implementation assumes the allocator never fails
// void* (*alloc) (size_t) = malloc;
#define alloc(a) malloc((a))
// void (*dealloc) (void*) = free;
#define dealloc(a) free((a))
// void* (*copy) (void*, const void*, size_t) = memcpy;
#define copy(a, b, c) memcpy((a), (b), (c))

#endif
