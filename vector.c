#include "vector.h"

#include <stdio.h>
#include <stdlib.h>

void vecInit(TVector* vec) {
    vec->values = malloc(sizeof(int));
    vec->capacity = 1;
    vec->size = 0;
}

void vecPushBack(TVector* vec, int value) {
    if (vec->size == vec->capacity) {
        vec->capacity += sizeof(int);
        vec->values = realloc(vec->values, vec->capacity);
    }
    vec->values[vec->size++] = value;
}

bool vecAt(TVector* vec, int index, int* out) {
    if (vec->size <= index) {
        return false;
    }
    *out = vec->values[index];
    return true;
}

bool vecRemove(TVector* vec, int index) {
    if (vec->size <= index) {
        return false;
    }
    for (int i = index; i < vec->size; i++) {
        vec->values[i - 1] = vec->values[i];
    }
    vec->capacity -= sizeof(int);
    vec->values = realloc(vec->values, vec->capacity);
    vec->size--;
    return true;
}

bool vecContains(TVector* vec, int value) {
    if (vec->size == 0) {
        return false;
    }

    for (int i = 0; i < vec->size; i++) {
        if (vec->values[i] == value) {
            return true;
        }
    }

    return false;
}

void vecFree(TVector* vec) {
    free(vec->values);
    vec->capacity = 0;
    vec->size = 0;
}

void vecPrint(TVector* vec) {
    printf("Values: [");
    for (int i = 0; i < vec->size; i++) {
        printf("%d", vec->values[i]);
        if (i != (vec->size - 1)) {
            printf(", ");
        }
    }
    printf("]\n");
}