#ifndef VECTOR_H
#define VECTOR_H
#include "tuple2.h"

typedef struct {
    tuple* positions;
    int length;
    int capacity;
    int count;
} vector; 

vector* push(vector* v, tuple t);
vector* create(int size);
tuple get(vector* v, int index);
void destroy(vector* v);
vector* reallocate_vec(vector* v);
#endif