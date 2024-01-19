#include "vector.h"

#include <stdio.h>
#include <stdlib.h>

bool vecInit(TVector* vec) {
    vec->values = malloc(sizeof(int));
    if (vec->values == NULL) {
        return false;
    }

    vec->capacity = 1;
    vec->size = 0;
    return true;
}

void vecPushBack(TVector* vec, int value) {
    if (vec->size == vec->capacity) {
        vec->capacity *= 2;
        vec->values = realloc(vec->values, vec->capacity * sizeof(int));
    }

    vec->values[vec->size++] = value;
}

bool vecFrom(TVector* vec, int data[], int count) {
    if (count <= 0) {
        return false;
    }

    for (int i = 0; i < count; i++) {
        vecPushBack(vec, data[i]);
    }

    if (vec->size != count) {
        return false;
    }

    return true;
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

    vec->capacity /= 2;
    vec->values = realloc(vec->values, vec->capacity * sizeof(int));
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

bool vecClear(TVector* vec) {
    // Do nothing if vector is already empty
    if (vec->size == 0 && vec->capacity == 1) {
        return true;
    }

    vec->capacity = 1;
    vec->values = realloc(vec->values, sizeof(int) * vec->capacity);
    if (vec->values == NULL) {
        return false;
    }
    vec->size = 0;

    return true;
}

bool vecEmpty(TVector* vec) {
    if (vec->size == 0 && vec->capacity == 1) {
        return true;
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