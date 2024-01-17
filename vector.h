#pragma once

#include <stdbool.h>
#include <stdint.h>

typedef struct Vector {
    int* values;
    int capacity;
    int size;
} TVector;

void vecInit(TVector* vec);
void vecPushBack(TVector* vec, int value);
bool vecAt(TVector* vec, int index, int* out);
bool vecRemove(TVector* vec, int index);
bool vecContains(TVector* vec, int value);
void vecFree(TVector* vec);
void vecPrint(TVector* vec);