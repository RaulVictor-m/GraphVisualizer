#include "mem.h"
#include "array_list.h"

#define MIN_CAP 16

struct ArrayList {
    void* data;
    size_t size, cap, elem_sz;
};

typedef enum {
    EmptyPop,
    IndexOutOfBounds,

} ErrorCode;

// private:

static void _error(ErrorCode code) {
    // may do something in the future
}

// doubles the list capacity every time its called
static void _grow(ArrayList vs) {
    vs->cap *= 2;

    void *big_data = alloc(vs->cap * vs->elem_sz);
    copy(big_data, vs->data, vs->elem_sz * vs->size);
    dealloc(vs->data);

    vs->data = big_data;
}

// shrinks the list capacity to be double the size
// OBS: does not shrink lower than MIN_CAP and
//      does not shrink if size is bigger than cap/4
static void _shrink(ArrayList vs) {
    if (vs->size > vs->cap/4 || vs->size * 2 < MIN_CAP) return;
    vs->cap = vs->size * 2;

    void *small_data = alloc(vs->cap * vs->elem_sz);
    copy(small_data, vs->data, vs->elem_sz * vs->size);
    dealloc(vs->data);

    vs->data = small_data;
}

// public:
ArrayList al_init(size_t n, size_t elem_size) { 
    ArrayList vs = alloc(sizeof(struct ArrayList));

    vs->size = n;
    vs->cap = n > MIN_CAP ? n : MIN_CAP;
    vs->elem_sz = elem_size;

    vs->data = alloc(vs->cap * vs->elem_sz);

    return vs; 
};

void al_clear(ArrayList vs) { 
    dealloc(vs->data);
    dealloc(vs);
};

size_t al_size(ArrayList vs) { return vs->size; };

void al_push_back(ArrayList vs, void *new_data) {
    if (vs->size == vs->cap) _grow(vs);

    copy(vs->data + vs->size * vs->elem_sz, new_data, vs->elem_sz);
    vs->size++;
}

void al_pop_back(ArrayList vs) {
    if (vs->size == 0) {
        _error(EmptyPop);
        return;
    }

    vs->size--;
    _shrink(vs);
}

void* al_at(ArrayList vs, size_t i) {
    if (i > vs->size) {
        _error(IndexOutOfBounds);
        return 0;
    }

    return vs->data + i*vs->elem_sz;
}

void* al_back(ArrayList vs) {
    return al_at(vs, vs->size-1);
}

void* al_front(ArrayList vs) {
    return al_at(vs, 0);
}
