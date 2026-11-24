#import "vector.h"
#import "stdio.h"
#import "stdlib.h"

vector* create(int size){
    vector* vec = malloc(sizeof(vector));
    if (vec == NULL){
        return NULL;
    } else {
        vec->positions = malloc(size * sizeof(tuple));
        if (vec->positions == NULL){
            free(vec);
            return NULL;
        }
        vec->capacity = size;
        vec->count = 0;
        return vec;
    }
}

vector* reallocate_vec(vector* v){
    printf("**REALLOCATING**");
    vector* vec = create(v->capacity * 2);
    if (vec == NULL){
        return NULL;
    }
    for (int i = 0 ; i < v->capacity; i++){
        vec->positions[i] = v->positions[i];
    }
    vec->count = v->count;
    free(v->positions);
    free(v);
    return vec;
}

vector* push(vector* v, tuple t){
    v->positions[v->count] = t;
    v->count++;
    if (v->count == v->capacity){
         v = reallocate_vec(v);
    }
    return v;
}

void print_vector(vector* v){
    for (int i = 0 ; i < v->capacity ; i++){
        printf("%d", v->positions[i].x);
    }
}

int main(void){
    tuple tup = {4, 5};
    tuple tup1 = {2, 9};
    tuple tup2 = {7, 3};
    tuple tup3 = {8, 3};
    tuple tup4 = {6, 6};

    vector* myfirstvector = create(2);
    myfirstvector = push(myfirstvector, tup);
    myfirstvector = push(myfirstvector, tup1);
    myfirstvector = push(myfirstvector, tup2);
    myfirstvector = push(myfirstvector, tup3);
    myfirstvector = push(myfirstvector, tup4);
    print_vector(myfirstvector);
    free(myfirstvector->positions);
    free(myfirstvector);
}